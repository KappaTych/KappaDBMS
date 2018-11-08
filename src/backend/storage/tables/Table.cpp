//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, nlohmann::fifo_map<std::string, dt::DataType> columns) : name(std::move(name)),
                                                                                                _columns(columns)
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
  for (auto &col : _columns) {
    result += col.first + " " + std::to_string(col.second) + ", ";
  }

  result.pop_back();
  result.pop_back();
  result += ");";
  return result;
}

namespace tables
{
void to_json(my_json &j, const Table &t)
{
  std::string result = "{\"name\":\"" + t.name + "\",\"columns\": [";

//  std::vector<std::pair<std::string, dt::DataType>> col;

  std::string prefix = "\"";
  for (auto &column : t.getColumns()) {
    result += prefix + column.first;
    prefix = "\",\"";
  }
  result += "\"],\"records\" : {";

  int index = 0;
  prefix = "";
  for (auto &record : t.records) {
    result += prefix + "\"" + std::to_string(index) + "\":" + "[";
    index++;
    std::string str = record.get();
    std::string buffer = "";
    prefix = "\"";
    std::string suffix = "\"";
    char ch;
    for (int i = 0; i < str.length(); ++i) {
      ch = str[i];
      if (ch == tables::DIVIDOR || i + 1 == str.length()) {
        if (i + 1 == str.length())
          buffer += ch;
        result += prefix + buffer + suffix;
        prefix = ",\"";
        buffer = "";
        continue;
      }
      buffer += ch;
    }
    prefix = ",";
    result += "]";
  }
  result += "}}";

  j = json::parse(result.begin(), result.end());
}
} //namespace tables