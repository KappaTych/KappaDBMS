//
// Created by truefinch on 02.11.18.
//

#pragma once

#include <cstdlib>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <json.hpp>
#include <fifo_map.hpp>

#include "tables/Table.h"
#include "datatypes/object.h"
#include "BlockManager.h"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{

class StorageEngine
{
public:
  static StorageEngine& Instance()
  {
    static se::StorageEngine instance;
    return instance;
  }

  bool hasMetaData(const std::string& metaData) const;

  my_json findMetaData(const std::string& metaData);

  bool create(std::string name, nlohmann::fifo_map<std::string, sql::DataType> columns);

  bool insert(std::string tableName, std::string input);

  std::string show_create(std::string name);

  my_json select(std::string tableName);

  bool flush();

  StorageEngine(StorageEngine const &) = delete;

  void operator=(StorageEngine const &) = delete;

public:
  se::BlockManager blockManager;

private:
  StorageEngine();

  ~StorageEngine() = default;

private:
  std::map<std::string, sql::Table> tables_;

};

} // namespace se