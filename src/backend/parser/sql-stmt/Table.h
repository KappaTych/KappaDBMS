#pragma once 

#include <string>
#include <iostream>

namespace sql {

class TableName {
public:
	TableName() = default;
	TableName(const TableName &t);

	std::string schema;
	std::string name;
};

enum class DataType {
  INT,
  DOUBLE,
  TEXT
};

std::ostream& operator<<(std::ostream&, DataType);

class ColumnDefinition {
 public:
  ColumnDefinition() = default;
  ColumnDefinition(const std::string &name, DataType type);

  std::string name;
  DataType type;
};


} // namespace sql
