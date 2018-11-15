//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <vector>
#include "datatypes/MemoryBlock.h"
#include "datatypes/Row.h"
#include "datatypes/MetaData.h"
#include <btree/btree_map.h>

namespace se
{

class BlockManager
{
public:
  std::map< std::string, std::shared_ptr<MemoryBlock> > freeBlocks_;
  std::map< std::string, std::shared_ptr<MemoryBlock> > takenBlocks_;
  MetaData metaData_;

  std::map< std::string, btree::btree_map<uint32_t, se::Row> > indexes_;

public:
  BlockManager() = default;
  BlockManager(std::ifstream& fin);

//  void readMetaData(std::ifstream& fin);
  void readData(std::ifstream& fin);

  void writeData(std::ofstream& fout);

//  void createIndex(std::string tableName, uint32_t columnIndex);

  void addRow(MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size);
};

} //namespace se
