//
// Created by truefinch on 29.10.18.
//
#pragma once

#include <string>
#include <vector>
#include "Record.h"
#include "../../include/json.hpp"
#include "../../include/fifo_map.hpp"

using json = nlohmann::json;

namespace tables
{

struct Column
{
  std::string name;
  dt::DataType dataType;
};

class Table
{
public:
  std::string name;
  std::vector<Record> records;

  explicit Table(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns);

  const nlohmann::fifo_map<std::string, dt::DataType> &getColumns()
  { return _columns; }

  std::string ToString();

private:
  nlohmann::fifo_map<std::string, dt::DataType> _columns;
};

} //namespace tables