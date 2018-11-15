//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <vector>
#include "datatypes/MemoryBlock.h"

namespace se
{

class BlockManager
{
public:
  std::vector< std::shared_ptr<MemoryBlock> > freeBlocks_;
  std::vector< std::shared_ptr<MemoryBlock> > takenBlocks_;

//  void pushBack(std::vector<MemoryBlock>);

//  void popBack(int number);


};

} //namespace se
