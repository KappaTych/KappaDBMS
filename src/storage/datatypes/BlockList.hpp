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
  
public:
  std::vector< std::shared_ptr<MemoryBlock> > freeBlocks_;
  std::vector< std::shared_ptr<MemoryBlock> > takenBlocks_;
  std::fstream file;

public:
  BlockList(std::string path);

  BlockList::size_t count() { return freeBlocks_.size() + takenBlocks_.size(); }

  void WriteData(const data_t* row, size_t size);

  // void ReadData(std::ifstream& fin);

  // void AddRow(MetaData& metaData, const char row[], size_t size);

  // void CreateIndex(std::string tableName, uint32_t columnIndex);

};

} //namespace se
