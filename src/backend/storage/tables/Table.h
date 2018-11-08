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

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace tables
{

const char DIVIDOR = '~';

struct Column
{
  std::string name;
  dt::DataType dataType;
};

class Table
{
public:
  std::string name;
  std::vector<std::shared_ptr<char>> records;

  explicit Table(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns);

  const nlohmann::fifo_map<std::string, dt::DataType> &getColumns() const
  { return _columns; }

  std::string ToString();

private:
  nlohmann::fifo_map<std::string, dt::DataType> _columns;
};

void to_json(my_json& j, const Table& t);

} //namespace tables