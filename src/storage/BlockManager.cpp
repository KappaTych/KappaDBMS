//
// Created by nixtaxe on 12.11.18.
//

#include "BlockManager.hpp"
#include "StorageEngine.hpp"

namespace se {

const std::string BlockManager::LoadBlockList(MetaData& metaData)
{
  auto j = metaData.data();
  std::string key = j.at("_path");
  if (data_.find(key) != data_.end()) {
    return key;
  }

  std::string path = StorageEngine::GetRootPath() + key;
  std::ifstream fin(path);
  if (!fin.is_open()) {
    std::ofstream fout(path);
    if (!fout.is_open())
      throw std::invalid_argument("StorageError: Couldn't create file " + path);
    fout.close();
  }
  data_.insert({key, 1});
  return key;
}

void BlockManager::AddRow(MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
  auto key = LoadBlockList(metaData);
  // auto fout = data_[key]->createOutputStream();
  // fout << "Hello\n";
}

} // namespace se