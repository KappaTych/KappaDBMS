#include "BlockManager.hpp"
#include "StorageEngine.hpp"

namespace se {

std::shared_ptr<BlockList> BlockManager::LoadBlockList(MetaData& metaData)
{
  auto j = metaData.data();
  std::string key = j.at("_path");
  auto it = data_.find(key);
  if (it != data_.end()) {
    return data_[key];
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
  return data_[key];
}

void BlockManager::Write(MetaData& metaData, const data_t* row, size_t size)
{
  auto blockList = LoadBlockList(metaData);
  blockList->WriteData(row, size);
}

std::shared_ptr<data_t> BlockManager::Read(MetaData& metaData, size_t start, size_t size)
{
  // TODO: existence checking
  auto blockList = LoadBlockList(metaData);
  // auto head = start - start % MemoryBlock::DEFAULT_CAPACITY;
  // for (auto& block : blockList->takenBlocks_) {
  //   if (block->offset() == head)
  // }
  return blockList->takenBlocks_.back().get()->data();
}

} // namespace se