// #pragma once 

// #include <string>
// #include <iostream>

// #include "../../storage/datatypes/object.h"


// namespace sql {

// class TableName {
// public:
// 	TableName() = default;
// 	TableName(const std::string&, const std::string&);

// 	std::string schema;
// 	std::string name;
// };

// // enum class DataType {
// //   INT,
// //   DOUBLE,
// //   TEXT
// // };

// sql::DataType convertDbType(sql::DataType);

// std::ostream& operator<<(std::ostream&, DataType);

// class ColumnDefinition
// {
//  public:
//   ColumnDefinition() = default;
//   explicit ColumnDefinition(const std::string &name, DataType type);

//   std::string name;
//   DataType type;
// };


// } // namespace sql
