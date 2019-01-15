#include "StorageEngine.hpp"


void se::StorageEngine::SetRootPath(const std::string& path)
{
  se::ROOT = path;
}

const std::string& se::StorageEngine::GetRootPath()
{
  return se::ROOT;
}

se::StorageEngine::StorageEngine() : blockManager(), meta_()
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

bool se::StorageEngine::Flush()
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

se::MetaData& se::StorageEngine::CreateData(const std::string& key)
{
  if (meta_.find(key) != meta_.end()) {
    throw std::invalid_argument("StorageError: Data already exists");
  }
  auto md = se::MetaData(key);
  blockManager.LoadBlockList(md);
  meta_.insert({key, md});
  Flush();
  return meta_.at(key);
}

se::MetaData& se::StorageEngine::GetMetaData(const std::string& key)
{
  if (meta_.find(key) == meta_.end()) {
    throw std::range_error("StorageError: No such metadata");
  }
  return meta_.at(key);
}

bool se::StorageEngine::HasMetaData(const std::string& key) const
{
  return meta_.find(key) != meta_.end();
}

void se::StorageEngine::Write(se::MetaData& metaData, const char* row, size_t size)
{
  blockManager.Write(metaData, row, size);
}

std::list<se::RawData> se::StorageEngine::Read(se::MetaData& metaData, size_t size, compare_t cmp)
{
  return std::move(blockManager.Read(metaData, size, cmp));
}