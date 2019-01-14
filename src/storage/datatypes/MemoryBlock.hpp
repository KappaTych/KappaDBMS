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

struct DataBlock
{
  DataBlock(data_t* data_, size_t size_) : data(data_), size(size_) { }

  data_t* data;
  size_t size;
};

class MemoryBlock
{
public:
  static const size_t DEFAULT_CAPACITY = 1024;
  // static const size_t DEFAULT_CAPACITY = 128000;

public:
  explicit MemoryBlock(index_t offset = 0) : offset_(offset), data_(new data_t[DEFAULT_CAPACITY], 0) { }
  explicit MemoryBlock(index_t offset, data_t* data, size_t size);

public:
  static const size_t realsize() { return DEFAULT_CAPACITY + sizeof(size_t); }
  bool isFree(size_t size) const { return data_.size + size < capacity_; }  
  size_t size() const { return data_.size; }
  size_t capacity() const { return capacity_; }
  index_t offset() const { return offset_; }
  MemoryBlock* next() const { return next_; }
  MemoryBlock* prev() const { return prev_; }
  std::shared_ptr<data_t> data() const { return std::shared_ptr<data_t>(data_.data); }

  void size(size_t size) { data_.size = size; }
  void capacity(size_t capacity) { capacity_ = capacity; }
  void offset(index_t offset) { offset_ = offset; }
  void next(MemoryBlock* index) { next_ = next_; }
  void prev(MemoryBlock* index) { prev_ = prev_; }

  MemoryBlock& operator<<(DataBlock&& data);
  // MemoryBlock& operator>>(DataBlock& data);

public:
   friend std::ostream&::operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);
   friend std::istream&::operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

private:
  size_t capacity_ = DEFAULT_CAPACITY;
  DataBlock data_;
  index_t offset_;
  MemoryBlock* next_;
  MemoryBlock* prev_;
};

} //namespace se