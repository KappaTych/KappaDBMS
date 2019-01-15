#include "BlockManager.hpp"
#include "StorageEngine.hpp"

namespace se {

BlockList& BlockManager::LoadBlockList(MetaData& metaData)
{
  auto j = metaData.data();
  std::string key = j.at("_path");
  auto it = data_.find(key);
  if (it != data_.end()) {
    return *data_[key];
  }

  std::string path = StorageEngine::GetRootPath() + key;
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

void BlockManager::Write(MetaData& metaData, const data_t* row, size_t size)
{
  auto& blockList = LoadBlockList(metaData);
  blockList.WriteData(row, size);
}

std::list<RawData> BlockManager::Read(MetaData& metaData, size_t size, compare_t cmp)
{
  // TODO: existence checking
  auto& blockList = LoadBlockList(metaData);
  std::list<RawData> result;
  for (auto it = blockList.begin(); it != blockList.end(); ++it) {
    auto& block = it.get();
    auto blockData = block.data();
    for (auto x = 0; x < block.size(); x += size) {
      if (cmp( RawData(blockData->data + x, size, false) )) {
        result.emplace_back(blockData->data + x, size);
      }
    }
  }
  return std::move(result);
}

} // namespace se