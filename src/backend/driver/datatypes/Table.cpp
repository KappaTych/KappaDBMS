#include "Table.hpp"

using json = nlohmann::json;


// TODO: Make a better solution
namespace std
{

string to_string(sql::DataType dataType)
{
  switch (dataType) {
    case sql::DataType::INTEGER : {
      return "INTEGER";
    }
    case sql::DataType::DOUBLE : {
      return "DOUBLE";
    }
    case sql::DataType::TEXT : {
      return "TEXT";
    }
    default : {
      return "";
    }
  }
}

} // namespace std


namespace sql
{

Table::Table(std::string name, nlohmann::fifo_map<std::string, DataType> columns)
  : name(std::move(name)),
    columns_(columns)
{ }

std::string Table::ToString()
{
  std::string result;
  result += name + " (";
  for (auto& col : columns_) {
    result += col.first + " " + std::to_string(col.second) + ", ";
  }

  result.pop_back();
  result.pop_back();
  result += ");";
  return result;
}

void to_json(my_json& j, const Table& t)
{
  std::string result = "{\"name\":\"" + t.name + "\",\"columns\": [";

  std::string prefix = "\"";
  for (auto &column : t.getColumns()) {
    result += prefix + column.first;
    prefix = "\",\"";
  }
  result += "\"],\"records\" : {";

  int index = 0;
  prefix = "";
  for (auto& record : t.records) {
    result += prefix + "\"" + std::to_string(index) + "\":" + "[";
    ++index;
    std::string str = record.get();
    std::string buffer = "";
    prefix = "\"";
    std::string suffix = "\"";
    char ch;
    for (int i = 0; i < str.length(); ++i) {
      ch = str[i];
      if (ch == sql::DIVIDER || i + 1 == str.length()) {
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

  j = json::parse(result.begin(), result.end()); // <--- WTF IS THIS? :D
}

} //namespace sql