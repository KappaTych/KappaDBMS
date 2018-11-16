//
// Created by nixtaxe on 10.11.18.
//

#include <iostream>
#include "MemoryBlock.hpp"

namespace se {

MemoryBlock::MemoryBlock(uint8_t* data, uint32_t size) : data_(new uint8_t[DEFAULT_CAPACITY]), size_(size)
{
  std::copy(data, data + size, data_.get());
};

} // namespace se

std::ostream& operator<<(std::ostream& fout, const se::MemoryBlock& memoryBlock)
{
  fout << memoryBlock.size();
  fout.write((char*) memoryBlock.data().get(), memoryBlock.capacity());
  return fout;
}

std::istream& operator>>(std::istream& fin, se::MemoryBlock& memoryBlock)
{
  fin >> memoryBlock.getSize();
  fin.read(reinterpret_cast<char*>(memoryBlock.data().get()), memoryBlock.capacity());
  return fin;
}