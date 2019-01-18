#include "StorageEngine.hpp"


namespace se {

void StorageEngine::SetRootPath(const std::string& path)
{
  se::ROOT = path;
}

const std::string& StorageEngine::GetRootPath()
{
  return se::ROOT;
}

StorageEngine::StorageEngine() : meta_()
{
  auto metaPath = GetRootPath() + META_DATA_PATH;

  auto dbDir = cppfs::fs::open(GetRootPath() + "database");
  if (!dbDir.isDirectory()) {
    dbDir.createDirectory();
  }

  std::ifstream fin(metaPath);
  if (!fin.is_open()) {
    std::ofstream fout(metaPath);
    if (!fout.is_open()) {
      throw std::invalid_argument("StorageError: Couldn't open metaData-file.");
    }
    fout << "{}";
    fout.close();
    fin.open(metaPath);
  }

  my_json j;
  fin >> j;
  if (!j.empty()) {
    for (auto it = j.begin(); it != j.end(); ++it) {
      meta_.insert({it.key(), it.value()});
    }
  }
}

BlockList& StorageEngine::LoadBlockList(MetaData& metaData)
{
  auto j = metaData.data();
  std::string key = j.at("_path");
  auto it = data_.find(key);
  if (it != data_.end()) {
    return *data_[key];
  }

  std::string path = GetRootPath() + key;
  std::ifstream fin(path);
  if (!fin.is_open()) {
    std::ofstream fout(path);
    if (!fout.is_open())
      throw std::invalid_argument("StorageError: Not allowed to create file " + path);
    fout.close();
  }
  fin.close();

  data_.insert( std::make_pair(std::string(key), std::make_shared<BlockList>(path)) );
  return *data_[key];
}

bool StorageEngine::Flush()
{
  // TODO: flush all loaded blocklists

  my_json j;
  std::ofstream fout( GetRootPath() + META_DATA_PATH );

  for (auto it = meta_.begin(); it != meta_.end(); ++it) {
    j[it->first] = it->second.data();
  }

  fout << j.dump();
  fout.close();

  return true;
}

MetaData& StorageEngine::CreateData(const std::string& key)
{
  if (meta_.find(key) != meta_.end()) {
    throw std::invalid_argument("StorageError: Data already exists " + key);
  }
  auto md = MetaData(key);
  LoadBlockList(md);
  meta_.insert({key, md});
  Flush();
  return meta_.at(key);
}

void StorageEngine::RemoveData(const std::string& key)
{
  auto it = meta_.find(key);
  if (it == meta_.end()) {
    throw std::invalid_argument("StorageError: Data does not exists " + key);
  }
  std::string path = it->second.data().at("_path");
  auto dataIter = data_.find(path);
  if (dataIter != data_.end()) {
    data_.erase(dataIter);
  }
  if (!cppfs::fs::open(GetRootPath() + path).remove()) {
    throw std::invalid_argument("StorageError: Couldn't remove data " + key);
  }
  meta_.erase(it);
  Flush();
}

MetaData& StorageEngine::GetMetaData(const std::string& key)
{
  if (meta_.find(key) == meta_.end()) {
    throw std::range_error("StorageError: No such metadata " + key);
  }
  return meta_.at(key);
}

bool StorageEngine::HasMetaData(const std::string& key) const
{
  return meta_.find(key) != meta_.end();
}

std::list<RawData> StorageEngine::Read(MetaData& metaData, size_t size, const compare_t& func)
{
  // TODO: existence checking
  auto& blockList = LoadBlockList(metaData);
  std::list<RawData> result;
  for (auto it = blockList.begin(); it != blockList.end(); ++it) {
    auto& block = it.get();
    auto& blockData = block.data();
    for (auto x = 0; x < block.size(); x += size) {
      if (func( RawData(blockData.data() + x, size, false) )) {
        result.emplace_back(blockData.data() + x, size);
      }
    }
  }
  return std::move(result);
}

void StorageEngine::Write(MetaData& metaData, const char* row, size_t size)
{
  auto& blockList = LoadBlockList(metaData);
  blockList.WriteData(row, size);
}

void StorageEngine::Update(MetaData& metaData, const size_t size, const update_t& func)
{
  auto& blockList = LoadBlockList(metaData);
  for (auto it = blockList.begin(); it != blockList.end(); ++it) {
    auto& block = it.get();
    auto& blockData = block.data();
    bool changed = false;
    for (auto x = 0; x < block.size(); x += size) {
      changed |= func( RawData(blockData.data() + x, size, false) );
    }
    if (changed) {
      blockList << block;
    }
  }
}

void StorageEngine::Delete(MetaData& metaData, size_t size, const compare_t& func)
{
  auto& blockList = LoadBlockList(metaData);
  RawData raw(MemoryBlock::DEFAULT_CAPACITY);
  for (auto it = blockList.begin(); it != blockList.end(); ++it) {
    auto& block = it.get();
    auto& blockData = block.data();
    for (auto x = 0; x < block.size(); x += size) {
      auto temp = RawData(blockData.data() + x, size, false);
      if (!func(temp)) {
        raw << temp;
      }
    }
    if (raw.size() == 0) {
      blockList.FreeBlock(block);
    } else if (blockData.size() != raw.size()) {
      block.data().FullReset();
      block << raw;
    }
    raw.FullReset();
  }
}

} // namespace se