//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <fstream>

//namespace se
//{

class MemoryBlock
{
public:
  static const uint32_t DEFAULT_CAPACITY = 128000;
  static const uint8_t DIVIDOR = 7;
public:
  uint32_t capacity_ = DEFAULT_CAPACITY;
  uint32_t size_ = 0;
  std::shared_ptr<uint8_t> data_;
  std::shared_ptr<MemoryBlock> next_;
public:
  MemoryBlock() : data_(new uint8_t[DEFAULT_CAPACITY]) {};

  explicit MemoryBlock(uint8_t* data, uint32_t capacity)
      : data_(data), capacity_(capacity), size_(sizeof(data))
  {};

  MemoryBlock(uint8_t* data, MemoryBlock* next, uint32_t capacity) : data_(data), next_(next),
                                                                                            capacity_(capacity)
  {};

  friend std::ofstream operator<<(std::ofstream& out, const MemoryBlock& memoryBlock);

  friend std::ifstream operator>>(std::ifstream& in, MemoryBlock memoryBlock);
};

//} //namespace se


