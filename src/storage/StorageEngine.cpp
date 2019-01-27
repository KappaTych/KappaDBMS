#include "StorageEngine.hpp"

#include "TransactionManager.hpp"

namespace se {

void StorageEngine::SetRootPath(const std::string& path)
{
  se::ROOT = path;
}

const std::string& StorageEngine::GetRootPath()
{
  return se::ROOT;
}

void StorageEngine::checkKey(const std::string &key)
{
  std::string path = GetRootPath() + key;
  std::ifstream fin(path);
  if (!fin.is_open()) {
    std::ofstream fout(path);
    if (!fout.is_open())
      throw std::invalid_argument("StorageError: Not allowed to create file " + path);
    fout.close();
  }
  fin.close();
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
  std::string name = j["private"]["path"];
  auto it = data_.find(name);
  if (it != data_.end()) {
    return *data_[name];
  }

  checkKey(name);

  data_.insert( std::make_pair(std::string(name), std::make_shared<BlockList>(GetRootPath() + name)) );
  return *data_[name];
}

bool StorageEngine::FlushMeta()
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

MetaData& StorageEngine::CreateData(uint64_t id, const std::string& key)
{
  if (TransactionManager::NO_TRANSACTION) {
    if (meta_.find(key) != meta_.end()) {
      throw std::invalid_argument("StorageError: Data already exists " + key);
    }
    auto md = MetaData(key);
    LoadBlockList(md);
    meta_.insert({key, md});
    FlushMeta();
    return meta_.at(key);
  } else {
    if (uncommittedMeta_.count(id) == 0) {
      throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
    }
    if (uncommittedMeta_.at(id).count(key) > 0) {
      throw std::invalid_argument("StorageError: Data already exists " + key);
    }
    auto md = MetaData(key);
    auto name = md.getName();

    checkKey(name);

    uncommittedData_.at(id).emplace(name, std::make_shared<BlockList>(GetRootPath() + name));
    uncommittedData_.at(id).at(name)->Clear(); // EmptyTable
    uncommittedMeta_.at(id).emplace(key, std::move(md));

    return uncommittedMeta_.at(id).at(key);
  }
}

void StorageEngine::UpdateMetaData(uint64_t  id, const std::string& key)
{
  if (TransactionManager::NO_TRANSACTION) {
    if (meta_.find(key) == meta_.end()) {
      throw std::invalid_argument("StorageError: Data doesn't exists " + key);
    }
    FlushMeta();
  }
}

void StorageEngine::RemoveData(uint64_t id, const std::string& key)
{
  if (TransactionManager::NO_TRANSACTION) {
    auto it = meta_.find(key);
    if (it == meta_.end()) {
      throw std::invalid_argument("StorageError: Data does not exists " + key);
    }
    std::string path = it->second.data()["private"]["path"];
    auto dataIter = data_.find(path);
    if (dataIter != data_.end()) {
      data_.erase(dataIter);
    }
    if (!cppfs::fs::open(GetRootPath() + path).remove()) {
      throw std::invalid_argument("StorageError: Couldn't remove data " + key);
    }
    meta_.erase(it);
    FlushMeta();
  } else {
    if (uncommittedMeta_.count(id) == 0) {
      throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
    }
    if (uncommittedMeta_.at(id).count(key) == 0) {
      throw std::invalid_argument("StorageError: Data does not exists " + key);
    }
    auto name = uncommittedMeta_.at(id).at(key).getName();

    uncommittedDropTable_.at(id)[name] = std::move(uncommittedData_.at(id).at(name)); // SaveBlock
    uncommittedMeta_.at(id).erase(key);
    uncommittedData_.at(id).erase(name);
  }
}

MetaData& StorageEngine::GetMetaData(uint64_t id, const std::string& key)
{
  if (TransactionManager::NO_TRANSACTION) {
    if (meta_.find(key) == meta_.end()) {
      throw std::range_error("StorageError: No such metadata " + key);
    }
    return meta_.at(key);
  } else {
    if (uncommittedMeta_.count(id) == 0) {
      throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
    }
    if (uncommittedMeta_.at(id).count(key) == 0) {
      throw std::range_error("StorageError: No such metadata " + key);
    }
    return uncommittedMeta_.at(id).at(key);
  }
}

bool StorageEngine::HasMetaData(uint64_t id, const std::string& key) const
{
  if (TransactionManager::NO_TRANSACTION) {
    return meta_.find(key) != meta_.end();
  } else {
    if (uncommittedMeta_.count(id) == 0) {
      throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
    }
    return uncommittedMeta_.at(id).count(key) != 0;
  }
}

std::list<RawData> StorageEngine::Read(BlockList& blockList, size_t size, const compare_t& func)
{
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

std::list<RawData> StorageEngine::Read(uint64_t id, MetaData& metaData, size_t size, const compare_t& func)
{
  if (TransactionManager::NO_TRANSACTION) {
    auto& blockList = LoadBlockList(metaData);
    return Read(blockList, size, func);
  } else {
    auto& blockList = getUncommittedBlockList(id, metaData);
    return Read(blockList, size, func);
  }
}

void StorageEngine::Write(BlockList& blockList, const char* row, size_t size)
{
  blockList.WriteData(row, size);
}

void StorageEngine::Write(uint64_t id, MetaData& metaData, const char* row, size_t size)
{
  if (TransactionManager::NO_TRANSACTION) {
    std::lock_guard<std::mutex> lock(m_writer);
    auto& blockList = LoadBlockList(metaData);
    Write(blockList, row, size);
    blockList.Flush();
    return;
  } else {
    auto& blockList = getUncommittedBlockList(id, metaData);
    Write(blockList, row, size);
    return;
  }
}

void StorageEngine::Update(BlockList& blockList, const size_t size, const update_t& func)
{
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

void StorageEngine::Update(uint64_t id, MetaData& metaData, const size_t size, const update_t& func)
{
  if (TransactionManager::NO_TRANSACTION) {
    std::lock_guard<std::mutex> lock(m_writer);
    auto& blockList = LoadBlockList(metaData);
    Update(blockList, size, func);
    blockList.Flush();
    return;
  } else {
    auto& blockList = getUncommittedBlockList(id, metaData);
    Update(blockList, size, func);
    return;
  }
}

void StorageEngine::Delete(BlockList& blockList, size_t size, const compare_t& func)
{
  RawData raw(MemoryBlock::DEFAULT_CAPACITY);
  std::vector<std::reference_wrapper<se::MemoryBlock>> block_delete;
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
      block_delete.emplace_back(block);
    } else if (blockData.size() != raw.size()) {
      block.data().FullReset();
      block << raw;
      blockList << block;
    }
    raw.FullReset();
  }
  for (auto block : block_delete) {
    blockList.FreeBlock(block);
  }
}

void StorageEngine::Delete(uint64_t id, MetaData& metaData, size_t size, const compare_t& func)
{
  if (TransactionManager::NO_TRANSACTION) {
    std::lock_guard<std::mutex> lock(m_writer);
    auto& blockList = LoadBlockList(metaData);
    Delete(blockList, size, func);
    blockList.Flush();
    return;
  } else {
    auto& blockList = getUncommittedBlockList(id, metaData);
    Delete(blockList, size, func);
    return;
  }
}

// For transaction

BlockList& StorageEngine::getUncommittedBlockList(uint64_t id, MetaData& metaData) {
  std::string name = metaData.getName();
  if (uncommittedMeta_.count(id) == 0) {
    throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
  }
  if (uncommittedData_.at(id).count(name) == 0) {
    throw std::invalid_argument("StorageError: No such metadata " + name);
  }
  return *(uncommittedData_.at(id).at(name));
}

uint64_t StorageEngine::StartTransaction()
{
  if (TransactionManager::NO_TRANSACTION) {
    return 0;
  }
  uint64_t newId = TransactionManager::Instance().NewTransaction();

  std::lock_guard<std::mutex> lock(m_writer);
  if (uncommittedMeta_.count(newId) > 0) {
    throw std::invalid_argument("Transaction " + std::to_string(newId) + " already exists");
  }

  std::unordered_map<std::string, MetaData> snapshotMeta;
  std::unordered_map<std::string, std::shared_ptr<BlockList>> snapshotData;

  for (auto& data : meta_) {
    std::string name = data.second.getName();
    checkKey(name);
    snapshotData.emplace(name, std::make_shared<BlockList>(GetRootPath() + name));
    snapshotMeta.emplace(data.first, data.second);
  }
  uncommittedMeta_.emplace(newId, std::move(snapshotMeta));
  uncommittedData_.emplace(newId, std::move(snapshotData));
  uncommittedDropTable_.emplace(newId, std::unordered_map<std::string, std::shared_ptr<BlockList>>()); // empty on default

  return newId;
}

void StorageEngine::RollBack(uint64_t id)
{
  if (TransactionManager::NO_TRANSACTION) {
    return;
  }
  if (uncommittedMeta_.count(id) == 0) {
    throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
  }
  uncommittedMeta_.erase(id);
  uncommittedData_.erase(id);
  uncommittedDropTable_.erase(id);
}

void StorageEngine::Commit(uint64_t id)
{
  if (TransactionManager::NO_TRANSACTION) {
    return;
  }
  std::lock_guard<std::mutex> lock(m_writer);
  if (uncommittedMeta_.count(id) == 0) {
    throw std::invalid_argument("Transaction " + std::to_string(id) + " doesn't exists");
  }

  // Flush
  for (auto& data : uncommittedDropTable_.at(id)) {
    if (uncommittedData_.at(id).count(data.first) == 0) {
      if (!cppfs::fs::open(GetRootPath() + data.first).remove()) {
        throw std::invalid_argument("StorageError: Couldn't remove data " + data.first);
      }
    }
  }

  my_json j;
  std::ofstream fout(GetRootPath() + META_DATA_PATH, std::ofstream::out | std::ofstream::trunc);
  for (auto& data : uncommittedMeta_.at(id)) {
    j[data.first] = data.second.data();
  }
  fout << j.dump();
  fout.close();

  for (auto& data : uncommittedData_.at(id)) {
    data.second->Flush();
  }

  meta_ = std::move(uncommittedMeta_.at(id));
  data_ = std::move(uncommittedData_.at(id));

  uncommittedMeta_.erase(id);
  uncommittedData_.erase(id);
  uncommittedDropTable_.erase(id);
}

} // namespace se