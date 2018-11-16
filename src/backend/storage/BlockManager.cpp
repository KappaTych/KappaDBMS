//
// Created by nixtaxe on 12.11.18.
//

#include <fstream>
#include "BlockManager.hpp"

void se::BlockManager::AddRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
  //
}

void se::BlockManager::LoadBlockList(se::MetaData& metaData)
{
  auto j = metaData.data();
  std::string path = j.at("_path");
  std::ofstream fout(path);
  if (!fout.is_open())
    throw std::invalid_argument("StorageError: Couldn't create file " + path);

  fout << (size_t)j.at("_size");
}
