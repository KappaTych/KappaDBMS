//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <vector>
#include <map>
#include <string>
#include "tables/Table.h"
#include "datatypes/object.h"
#include "../include/json.hpp"
#include "../include/fifo_map.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{
class StorageEngine
{
public:
  static StorageEngine &getInstance()
  {
    static se::StorageEngine instance;
    return instance;
  }

  bool create(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns);

  std::string show_create(std::string name);

  bool flush();

  StorageEngine(StorageEngine const &) = delete;

  void operator=(StorageEngine const &)  = delete;

private:
  StorageEngine()
  {};

  ~StorageEngine() = default;

  std::map<std::string, tables::Table> _tables;
};
} // namespace se


