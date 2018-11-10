//
// Created by truefinch on 29.10.18.
//

#pragma once

#include <string>
#include <vector>
#include <json.hpp>
#include <fifo_map.hpp>

#include "Record.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace sql
{

const char DIVIDER = '~';

struct Column
{
  std::string name;
  DataType dataType;
};

class Table
{
public:
  std::string name;
  std::vector< std::shared_ptr<char> > records;

  explicit Table(std::string name, nlohmann::fifo_map<std::string, DataType> columns);

  const nlohmann::fifo_map<std::string, DataType>& getColumns() const { return columns_; }

  std::string ToString();

private:
  nlohmann::fifo_map<std::string, DataType> columns_;
};

void to_json(my_json& j, const Table& t);

} //namespace sql