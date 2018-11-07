//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns) : name(
    std::move(name)), _columns(columns)
{
}

namespace std
{
std::string to_string(dt::DataType dataType)
{
  switch (dataType) {
    case dt::DataType::INTEGER : {
      return "INTEGER";
    }
    case dt::DataType::DOUBLE : {
      return "DOUBLE";
    }
    case dt::DataType::TEXT : {
      return "TEXT";
    }
    default: {
      return "";
    }
  }
}
};

std::string tables::Table::ToString()
{
  std::string result;
  result += name + " (";
  for (auto& col : _columns) {
    result += col.first + " " + std::to_string(col.second) + ", ";
  }

  result.pop_back();
  result.pop_back();
  result += ");";
  return result;
}