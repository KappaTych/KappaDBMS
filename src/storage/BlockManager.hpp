#pragma once

#include <list>
#include <memory>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <btree/btree_map.h>

#include "datatypes/MemoryBlock.hpp"
#include "datatypes/BlockList.hpp"
#include "datatypes/MetaData.hpp"
#include "datatypes/RawData.hpp"

namespace se {

class BlockManager
{
public:
  // std::map< std::string, btree::btree_map<uint32_t, se::RawData> > indexes_;
  std::unordered_map<std::string, std::shared_ptr<BlockList>> data_;

public:
  BlockManager() = default;

  BlockList& LoadBlockList(MetaData& metaData);
  void Write(MetaData& metaData, const data_t* row, size_t size);
  std::list<RawData> Read(MetaData& metaData, size_t size, compare_t cmp);

//  void CreateIndex(std::string tableName, uint32_t columnIndex);

};

} //namespace se
