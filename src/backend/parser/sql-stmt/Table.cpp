#include "Table.h"

namespace sql {

TableName::TableName(const std::string & s, const std::string & n) : schema(s), name(n) {};

ColumnDefinition::ColumnDefinition(const std::string &name, DataType type) :
  name(name),
  type(type) {};

std::ostream& operator<<(std::ostream &st, DataType type) {
  switch (type) {
    case DataType::INT:
      st << "INT";
      break;
    case DataType::DOUBLE:
      st << "DOUBLE";
      break;
    case DataType::TEXT:
      st << "TEXT";
      break;
  }
  return st;
}

} // namespace sql
