#include "BlockList.hpp"

namespace se {

BlockList::BlockList(std::string path)
  : file(path, std::fstream::in | std::fstream::out | std::fstream::ate | std::fstream::binary)
{
  BlockList::size_t count = file.tellg() / MemoryBlock::realsize();
  if (count == 0) return;

  MemoryBlock* memoryBlocks = new MemoryBlock[count];
  for (auto i = 0; i < count; ++i) {
    file >> memoryBlocks[i];
    memoryBlocks[i].offset(i * MemoryBlock::DEFAULT_CAPACITY);
    if (memoryBlocks[i].size() > 0) {
      takenBlocks_.emplace_back(memoryBlocks + i);
    } else {
      freeBlocks_.emplace_back(memoryBlocks + i);
    }
  }
}

void BlockList::WriteData(const data_t* row, size_t size)
{
  // TODO: check if size of data is greater than size of empty block
  // TODO: copy-on-write
  if (takenBlocks_.empty()) {
    if (freeBlocks_.empty()) {
      takenBlocks_.emplace_back(new MemoryBlock(this->count() * MemoryBlock::DEFAULT_CAPACITY));
    } else {
      takenBlocks_.push_back(std::move(freeBlocks_.back()));
      freeBlocks_.pop_back();
    }
  }
  if (!takenBlocks_.back()->isFree(size)) {
    takenBlocks_.emplace_back(new MemoryBlock(this->count() * MemoryBlock::DEFAULT_CAPACITY));
  }
  auto& block = *takenBlocks_.back();
  block << DataBlock((data_t*) row, size);
  file << block;
}

} // namespace se