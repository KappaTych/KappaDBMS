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
  std::cout << metaPath << std::endl;
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
  my_json j;
  std::ofstream fout( GetRootPath() + META_DATA_PATH );

  for (auto it = meta_.begin(); it != meta_.end(); ++it) {
    j[it->first] = it->second.data();
    // fout.open("./database/" + it.first + ".kp", std::ios_base::binary);
    // for (auto record : it.second.records)
    //   if (record.get() != NULL) {
    //     fout.write(record.get(), sizeof(record.get()));
    //   }
    // fout.close();
  }

  // std::string result = j.dump();
  // fout.open( GetRootPath() + META_DATA_PATH );
  // if (!fout.is_open()) {
  //   return false;
  // }

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

void se::StorageEngine::AddRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
  blockManager.AddRow(metaData, row, size);
}
