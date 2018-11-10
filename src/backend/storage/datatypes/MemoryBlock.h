//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <fstream>

namespace se
{

class MemoryBlock
{
public:
  static const uint32_t DEFAULT_CAPACITY = 128000;
  static const uint8_t DIVIDOR = 7;
public:
  uint32_t capacity_;
  uint32_t size_;
  std::shared_ptr<uint8_t> data_;
  std::shared_ptr<se::MemoryBlock> next_;
public:
  MemoryBlock() = default;

  explicit MemoryBlock(uint8_t* data, uint32_t capacity = DEFAULT_CAPACITY)
      : data_(data), capacity_(capacity), size_(sizeof(data))
  {};

  MemoryBlock(uint8_t* data, se::MemoryBlock* next, uint32_t capacity = DEFAULT_CAPACITY) : data_(data), next_(next),
                                                                                            capacity_(capacity)
  {};

  std::ofstream operator<<(std::ofstream& out);

  std::ifstream operator>>(std::ifstream& in);
};

} //namespace se
