#pragma once

#include <memory>
#include <fstream>
#include <istream>
#include <vector>
#include <unordered_map>
#include <btree/btree_map.h>

#include "MemoryBlock.hpp"

namespace se {

class BlockList
{
public:
  using size_t = uint32_t;
  using container_t = std::unordered_map<size_t, MemoryBlock>;
  
public:
  class iterator : public std::vector<size_t>::iterator
  {
  public:
    iterator(std::vector<size_t>::iterator it, BlockList& list) : std::vector<size_t>::iterator(it), blockList(list) { }

    BlockList& blockList;
    MemoryBlock& get() { return blockList.LoadBlock(**this); };
  };

public:
  container_t blocks_;
  std::vector<size_t> freeBlocks_;
  std::vector<size_t> takenBlocks_;
  std::fstream file;

// TODO: add offset field for overloading MemoryBlock::OFFSET_CAPACITY

public:
  BlockList(std::string path);

  void WriteData(const data_t* row, size_t size);

  iterator begin() { return iterator(takenBlocks_.begin(), *this); }
  iterator end() { return iterator(takenBlocks_.end(), *this); }

  MemoryBlock& GetFreeBlock(size_t size = 0);
  MemoryBlock& LoadBlock(size_t offset = 0);

  BlockList& operator<<(const MemoryBlock& block);

  BlockList::size_t Count();

  // void ReadData(std::ifstream& fin);

  // void AddRow(MetaData& metaData, const char row[], size_t size);

  // void CreateIndex(std::string tableName, uint32_t columnIndex);

};

} //namespace se
