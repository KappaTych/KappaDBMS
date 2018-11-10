#pragma once

#include <string>
#include <vector>
#include <json.hpp>
#include <fifo_map.hpp>
#include <parser/sql.hpp>

#include "Record.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace sql
{

const char DIVIDER = '~';

void to_json(my_json& j, const Table& t);


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

} //namespace sql

// NLOHMANN_JSON_SERIALIZE_ENUM(cmd::LiteralType, {
//   { cmd::LiteralType::BOOL,    "BOOL" },
//   { cmd::LiteralType::INTEGER, "INTEGER" },
//   { cmd::LiteralType::DOUBLE,  "DOUBLE" },
//   { cmd::LiteralType::TEXT,    "TEXT" }
// });