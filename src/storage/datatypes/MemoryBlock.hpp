#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <memory>
#include <fstream>

#include "RawData.hpp"

namespace se {

class MemoryBlock;

} // namespace se

std::ostream& operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);
std::istream& operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

namespace se {

class MemoryBlock
{
public:
  static const size_t DEFAULT_CAPACITY = 1024;
  static const size_t OFFSET_CAPACITY = DEFAULT_CAPACITY + sizeof(se::size_t);
  // static const size_t DEFAULT_CAPACITY = 128000;

public:
  explicit MemoryBlock(index_t offset = 0);
  explicit MemoryBlock(index_t offset, data_t* data, size_t size);

public:
  bool isFree(size_t size) const { return data_.size() + size < data_.capacity(); }  
  size_t size() const { return data_.size(); }
  size_t capacity() const { return data_.capacity(); }
  index_t offset() const { return offset_; }
  const RawData& data() const { return data_; }

  void offset(index_t offset) { offset_ = offset; }

  MemoryBlock& operator<<(RawData& data);
  MemoryBlock& operator<<(RawData&& data);
  // MemoryBlock& operator>>(RawData& data);

public:
   friend std::ostream&::operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);
   friend std::istream&::operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

private:
  RawData data_;
  index_t offset_;
};

} //namespace se