#include "BlockList.hpp"

namespace se {

BlockList::BlockList(std::string path)
  : file(path, std::fstream::in | std::fstream::out | std::fstream::ate | std::fstream::binary),
    blocks_()
{
  // TODO: handling exceptions related to file
  BlockList::size_t count = file.tellg() / MemoryBlock::OFFSET_CAPACITY;
  if (count == 0) return;

  blocks_.reserve(count);

  for (BlockList::size_t i = 0, size = 0, offset = 0; i < count; ++i, offset += MemoryBlock::OFFSET_CAPACITY) {
    size = file.seekg(offset, file.beg).peek();
    if (size > 0) {
      takenBlocks_.push_back(offset);
    } else {
      freeBlocks_.push_back(offset);
    }
  }
}

BlockList::size_t BlockList::Count()
{
  return freeBlocks_.size() + takenBlocks_.size();
}

void BlockList::WriteData(const data_t* row, size_t size)
{
  // TODO: check if size of data is greater than size of empty block
  // TODO: copy-on-write
  auto& block = GetFreeBlock(size);
  block << DataBlock((data_t*) row, size);
  file << block;
}

MemoryBlock& BlockList::LoadBlock(size_t offset)
{
  // NOTE: due to map rehashing it would be dangerous to return iterator
  auto result = blocks_.emplace(std::make_pair(offset, offset));
  if (!result.second) {
    return blocks_[offset];
  }
  file.seekg(offset);
  file.peek();
  if (file.eof()) {
    file.clear();
    file << result.first->second;
  } else {
    file >> result.first->second;
  }
  if (file.fail()) {
    file.clear();
  }
  return result.first->second;
}

MemoryBlock& BlockList::GetFreeBlock(size_t size)
{
  BlockList::size_t offset = 0;
  if (takenBlocks_.empty()) {
    if (!freeBlocks_.empty()) {
      offset = freeBlocks_.back();
      freeBlocks_.pop_back();
    }
    takenBlocks_.push_back(offset);
  } else {
    offset = takenBlocks_.back();
  }
  auto& block = LoadBlock(offset);
  if (block.isFree(size)) {
    return block;
  }
  takenBlocks_.push_back(offset + MemoryBlock::OFFSET_CAPACITY);
  return LoadBlock(offset + MemoryBlock::OFFSET_CAPACITY);
}

} // namespace se