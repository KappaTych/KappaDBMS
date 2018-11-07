//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, std::map<std::string, dt::DataType> columns) : name(
    std::move(name)), _columns(columns.begin(), columns.end())
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
  for (auto col = _columns.begin(); col != _columns.end(); ++col) {
    result += col->first + " " + std::to_string(col->second) + (std::next(col) == _columns.end() ? "" : ", ");
  }

  result += ");";
  return result;
}