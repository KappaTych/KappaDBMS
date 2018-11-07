//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <vector>
#include <map>
#include <string>
#include "tables/Table.h"
#include "datatypes/object.h"

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

  bool create(std::string name, std::vector<std::pair<std::string, dt::DataType>> columns);

  tables::Table show_create();

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


