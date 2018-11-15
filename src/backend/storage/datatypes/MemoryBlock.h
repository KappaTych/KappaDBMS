//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <fstream>

namespace se
{
class MemoryBlock;
}

std::ostream& operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);

std::istream& operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

namespace se
{

class MemoryBlock
{
public:
  using size_t = uint32_t;
  using data_t = uint8_t;
  using index_t = uint32_t;

public:
  static const size_t DEFAULT_CAPACITY = 128000;
  static const data_t DIVIDOR = 7;
  static const index_t offset = sizeof(size_t);

public:
  MemoryBlock() : data_(new data_t[DEFAULT_CAPACITY])
  {};

  explicit MemoryBlock(data_t* data, size_t size);

public:
  size_t size() const
  { return size_; }

  size_t& getSize()
  { return size_; }

  size_t capacity() const
  { return capacity_; }

  std::shared_ptr<data_t> data() const
  { return data_; }

  std::shared_ptr<data_t> getData()
  { return data_; }

  index_t next() const
  { return next_; }

  index_t getNext()
  { return next_; }

public:
  friend std::ostream&::operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);

  friend std::istream&::operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

private:
  size_t capacity_ = DEFAULT_CAPACITY;
  size_t size_ = 0;
  std::shared_ptr<data_t> data_;
  index_t next_;
};

} //namespace se


