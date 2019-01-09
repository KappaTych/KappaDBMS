#include "Table.hpp"
#include <vector>

using json = nlohmann::json;

namespace sql {

std::string to_string(cmd::LiteralType t)
{
  switch (t) {
    case cmd::LiteralType::INTEGER : {
      return "INTEGER";
    }
    case cmd::LiteralType::DOUBLE : {
      return "DOUBLE";
    }
    case cmd::LiteralType::TEXT : {
      return "TEXT";
    }
    case cmd::LiteralType::BOOL : {
      return "BOOL";
    }
    default: {
      return "UNKNOWN";
    }
  }
}

void to_json(json& j, const Table& t)
{
  j["name"] = t.name_.name_;
  j["database"] = t.name_.database_;
  j["schema"] = t.name_.schema_;

  std::vector<json> columns;
  for (auto &column : t.GetColumns()) {
    json c;
    c["name"] = column.name_;
    c["type"] = to_string(column.type_);
    columns.push_back(c);
  }
  j["columns"] = json(columns);

  std::vector<json> records;
  for (auto &record: t.GetRecords()) {
    std::vector<std::string> r;
    for (auto field : record.GetFields()) {

    }
    records.push_back(r);
  }
  j["records"] = records;
}

void from_json(const json& j, Table& t)
{
  j.at("name").get_to(t.name_.name_);
}

void Table::AddColumn(cmd::ColumnDefinition column)
{
  columns_.push_back(column);
}

void Table::InsertRecord(Record record)
{
  records_.push_back(record);
}

void Table::DeleteRecord(int index)
{
  auto it = records_.begin();
  while (index > 0) {
    --index;
    ++it;
  }
  records_.erase(it);
}

std::string Table::ToString() const
{
  std::string result = "CREATE TABLE " + name_.ToString() + " (";
  // for (auto &col : columns_) {
  //   result += col.name_ + " " + sql::to_string(col.type_) + ", ";
  // }

  // result.pop_back();
  // result.pop_back();
  // result += ");";
  return result;
}

// void to_json(my_json& j, const Table& t)
// {
//   std::string result = "{\"name\":\"" + t.name + "\",\"columns\": [";

//   std::string prefix = "\"";
//   for (auto &column : t.getColumns()) {
//     result += prefix + column.first;
//     prefix = "\",\"";
//   }
//   result += "\"],\"records\" : {";

//   int index = 0;
//   prefix = "";
//   for (auto& record : t.records) {
//     result += prefix + "\"" + std::to_string(index) + "\":" + "[";
//     ++index;
//     std::string str = record.get();
//     std::string buffer = "";
//     prefix = "\"";
//     std::string suffix = "\"";
//     char ch;
//     for (int i = 0; i < str.length(); ++i) {
//       ch = str[i];
//       if (ch == sql::DIVIDER || i + 1 == str.length()) {
//         if (i + 1 == str.length())
//           buffer += ch;
//         result += prefix + buffer + suffix;
//         prefix = ",\"";
//         buffer = "";
//         continue;
//       }
//       buffer += ch;
//     }
//     prefix = ",";
//     result += "]";
//   }
//   result += "}}";

//   j = json::parse(result.begin(), result.end()); // <--- WTF IS THIS? :D
// }

} //namespace sql