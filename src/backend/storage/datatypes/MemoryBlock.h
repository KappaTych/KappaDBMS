//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <fstream>

namespace se {class MemoryBlock;}

std::ostream& operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);

std::istream& operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

namespace se
{

class MemoryBlock
{
public:
  static const uint32_t DEFAULT_CAPACITY = 128000;
  static const uint8_t DIVIDOR = 7;

public:
  MemoryBlock() : data_(new uint8_t[DEFAULT_CAPACITY]) {};

  explicit MemoryBlock(uint8_t* data, uint32_t size);

  MemoryBlock(uint8_t* data, MemoryBlock* next) : data_(data_), next_(next)
  {  };

public:
  uint32_t size() const { return size_; }

  uint32_t capacity() const { return capacity_; }

  std::shared_ptr<uint8_t> data() const { return data_; }

  std::shared_ptr<MemoryBlock> next() const { return next_; }

public:
  friend std::ostream& ::operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock);

  friend std::istream& ::operator>>(std::istream& in, se::MemoryBlock& memoryBlock);

private:
  uint32_t capacity_ = DEFAULT_CAPACITY;
  uint32_t size_ = 0;
  std::shared_ptr<uint8_t> data_;
  std::shared_ptr<MemoryBlock> next_;
};

} //namespace se


