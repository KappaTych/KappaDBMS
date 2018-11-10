//
// Created by nixtaxe on 10.11.18.
//

#include "MemoryBlock.h"

std::ofstream operator<<(std::ofstream& fout, const MemoryBlock& memoryBlock)
{
  fout.write((char*) &memoryBlock.data_, memoryBlock.size_);
}

std::ifstream operator>>(std::ifstream& fin, MemoryBlock memoryBlock)
{
//  memoryBlock.data_.get(std::istreambuf_iterator<char>(fin));
  fin.read(reinterpret_cast<char*>(memoryBlock.data_.get()), sizeof(memoryBlock.data_.get()));
}