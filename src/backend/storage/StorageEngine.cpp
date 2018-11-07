//
// Created by truefinch on 02.11.18.
//

#include <iostream>
#include <fstream>
#include "StorageEngine.h"

bool se::StorageEngine::create(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns)
{
  _tables.insert(std::pair<std::string, tables::Table>(name, tables::Table(name, columns)));
  //TODO: remove columns with some stream of pare values - column name and column type
  if (flush())
    return true;
  else false;
}

using json = nlohmann::json;

bool se::StorageEngine::flush()
{
  my_json j;
  for (auto &table : _tables) {
    j[table.first] = table.second.getColumns();
  }

  std::string result = j.dump();
  std::ofstream fout("../database/tables.json");
  fout << result;
  fout.flush();
  fout.close();
}

std::string se::StorageEngine::show_create(std::string name)
{
  std::ifstream fin("../database/tables.json");
  my_json j;
  fin >> j;
  tables::Table t = tables::Table(name, j[name]);
  return "CREATE TABLE " + t.ToString();
}
