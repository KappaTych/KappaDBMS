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
  std::vector< std::shared_ptr<se::MemoryBlock> > freeBlocks_;
};

} //namespace se
