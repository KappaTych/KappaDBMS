//
// Created by truefinch on 02.11.18.
//

#include "StorageEngine.h"

se::StorageEngine::StorageEngine()
{
  std::ifstream fin(META_DATA_PATH);
  blockManager = se::BlockManager(fin);
}

bool se::StorageEngine::flush()
{
  my_json j;
  std::ofstream fout;

  for (auto &table : tables_) {
    j[table.first] = table.second.getColumns();
    fout.open("./database/" + table.first + ".kp", std::ios_base::binary);
    for (auto record : table.second.records)
      if (record.get() != NULL) {
        fout.write(record.get(), sizeof(record.get()));
      }
    fout.close();
  }

  std::string result = j.dump();
  fout.open(se::StorageEngine::META_DATA_PATH);
  if (!fout.is_open()) {
    return false;
  }
  fout << result;
  fout.close();

  return true;
}

se::MetaData& se::StorageEngine::createData(se::MetaData& metaData)
{
  metaData.data()->at(name);
  blockManager.createFile(metaData);
}

se::MetaData se::StorageEngine::getMetaData(const std::string& metaData)
{
  std::ifstream fin;
  fin.open(se::StorageEngine::META_DATA_PATH);
  if (!fin.is_open()) {
    throw std::invalid_argument("No such file or directory.");
  }

  se::MetaData j;
  j.read(fin);
  fin.close();
  if (j.data()->find(metaData) == j.data()->end())
    throw std::range_error("No such table");

  return se::MetaData(j.data()->at(metaData));
}

void se::StorageEngine::addRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
  blockManager.addRow(metaData, row, size);
}
