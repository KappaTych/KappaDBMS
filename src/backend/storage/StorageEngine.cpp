//
// Created by truefinch on 02.11.18.
//

#include <iostream>
#include <fstream>
#include "StorageEngine.h"

se::StorageEngine::StorageEngine() : _tables()
{
  std::ifstream fin("../database/tables.json");
  if (fin.is_open()) {
    my_json j;
    fin >> j;
    fin.close();
    for (auto it = j.begin(); it != j.end(); ++it) {
      _tables.insert(std::pair<std::string, tables::Table>(it.key(), tables::Table(it.key(), it.value())));

      fin.open("../database/" + it.key() + ".kp", std::ios_base::binary);
      if (!fin.is_open())
        continue;
      char ch;
      while (fin >> ch) {
        std::string s = "";
        while (ch != 0) {
          s += ch;
          fin >> ch;
        }
        auto size = s.size() + 1;
        _tables.at(it.key()).records.push_back(std::make_shared<char>(size));
        std::memcpy(_tables.at(it.key()).records.back().get(), s.c_str(), size);
      }
      fin.close();
    };
  }
}

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
  std::ofstream fout;
  for (auto &table : _tables) {
    j[table.first] = table.second.getColumns();
    fout.open("../database/" + table.first + ".kp", std::ios_base::binary);
    for (auto record : table.second.records)
      if (record.get() != NULL) {
        fout.write(record.get(), sizeof(record.get()));
      }
    fout.close();
  }

  std::string result = j.dump();
  fout.open("../database/tables.json");
  fout << result;
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

bool se::StorageEngine::insert(const std::string tableName, std::string input)
{
  if (_tables.find(tableName) == _tables.end()) {
    return false;
  }

  auto &t = _tables.at(tableName);
  auto size = input.size() + 1;
  t.records.push_back(std::make_shared<char>(size));
  std::memcpy(t.records.back().get(), input.c_str(), size);
  flush();
  return true;
}

my_json se::StorageEngine::select(std::string tableName)
{
  if (_tables.find(tableName) == _tables.end()) {
    return my_json();
  }

  tables::Table &t = _tables.at(tableName);
  my_json j;
  tables::to_json(j, t);
  return j;
}
