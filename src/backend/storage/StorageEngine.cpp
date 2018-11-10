//
// Created by truefinch on 02.11.18.
//

#include "StorageEngine.h"

se::StorageEngine::StorageEngine() : tables_()
{
  auto dir = system("mkdir database"); // TODO: fix this workaround
  std::ifstream fin("./database/tables.json");
  if (fin.is_open()) {
    my_json j;
    fin >> j;
    fin.close();
    for (auto it = j.begin(); it != j.end(); ++it) {
      tables_.insert(std::pair<std::string, sql::Table>(it.key(), sql::Table(it.key(), it.value())));

      fin.open("./database/" + it.key() + ".kp", std::ios_base::binary);
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
        tables_.at(it.key()).records.push_back(std::make_shared<char>(size));
        std::memcpy(tables_.at(it.key()).records.back().get(), s.c_str(), size);
      }
      fin.close();
    };
  }
}

bool se::StorageEngine::create(std::string name, nlohmann::fifo_map<std::string, sql::DataType> columns)
{
  tables_.insert(std::pair<std::string, sql::Table>(name, sql::Table(name, columns)));
  if (flush())
    return true;
  return false;
}

using json = nlohmann::json;

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
  fout.open("./database/tables.json");
  if (!fout.is_open()) {
    return false;
  }
  fout << result;
  fout.close();

  return true;
}

std::string se::StorageEngine::show_create(std::string name)
{
  std::ifstream fin("./database/tables.json");
  my_json j;
  fin >> j;
  sql::Table t = sql::Table(name, j[name]);
  return "CREATE TABLE " + t.ToString();
}

bool se::StorageEngine::insert(const std::string tableName, std::string input)
{
  if (tables_.find(tableName) == tables_.end()) {
    return false;
  }

  auto &t = tables_.at(tableName);
  auto size = input.size() + 1;
  t.records.push_back(std::make_shared<char>(size));
  std::memcpy(t.records.back().get(), input.c_str(), size);
  flush();
  return true;
}

my_json se::StorageEngine::select(std::string tableName)
{
  if (tables_.find(tableName) == tables_.end()) {
    return my_json();
  }

  sql::Table& t = tables_.at(tableName);
  my_json j;
  sql::to_json(j, t);
  return j;
}