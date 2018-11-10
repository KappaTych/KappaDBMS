//
// Created by nixtaxe on 10.11.18.
//

#include "MemoryBlock.h"

std::ofstream se::MemoryBlock::operator<<(std::ofstream& out)
{
  out.write((char*) &data_, size_);
//  return out;
}

std::ifstream se::MemoryBlock::operator>>(std::ifstream& in)
{
  in.read((char*)data_.get(), MemoryBlock::DEFAULT_CAPACITY);
//  return in;
}
