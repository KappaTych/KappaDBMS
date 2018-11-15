//
// Created by nixtaxe on 12.11.18.
//

#include <fstream>
#include "BlockManager.h"

se::BlockManager::BlockManager(std::ifstream& fin)
{
  metaData_ = se::MetaData(fin);
}

void se::BlockManager::addRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
}
