//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <vector>
#include <btree/btree_map.h>

#include "datatypes/MemoryBlock.hpp"
#include "datatypes/MetaData.hpp"
#include "datatypes/Row.hpp"

namespace se
{

class BlockManager
{
public:
  std::map< std::string, std::shared_ptr<MemoryBlock> > freeBlocks_;
  std::map< std::string, std::shared_ptr<MemoryBlock> > takenBlocks_;

  std::map< std::string, btree::btree_map<uint32_t, se::Row> > indexes_;

public:
  BlockManager() = default;

  void LoadBlockList(MetaData& metaData);

  void WriteData(std::ofstream& fout);

  void ReadData(std::ifstream& fin);

  void AddRow(MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size);

//  void CreateIndex(std::string tableName, uint32_t columnIndex);

};

} //namespace se
