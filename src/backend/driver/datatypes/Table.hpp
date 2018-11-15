#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <json.hpp>
#include <fifo_map.hpp>
#include <parser/sql.hpp>
#include <storage/StorageEngine.h>
#include "Record.hpp"

namespace sql
{

using TabDef = cmd::TableDefinition;
using Cols = std::vector<cmd::ColumnDefinition>;
using Rows = std::vector<Record>;

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
      return "TEXT";
    }
    default: {
      return "UNKNOWN";
    }
  }
}

class Table
{
public:
// TODO: Fix this constructors:
  explicit Table(cmd::TableDefinition name) 
      : 
      name_(name),
      meta_(name.ToString()) {}

  explicit Table(
    cmd::TableDefinition name,
    std::list<cmd::ColumnDefinition> columns,
    ) 
      : 
      name_(name),
      columns_(columns),
      meta_(name.ToString()) {}

  explicit Table(
    cmd::TableDefinition name,
    std::list<cmd::ColumnDefinition> columns,
    std::list<Record> records)
      : 
      name_(name),
      columns_(columns),
      records_(records),
      meta_(name.ToString()) {}

  void AddColumn(cmd::ColumnDefinition column);
  void InsertRecord(Record record);
  void DeleteRecord(int index);

  const std::list<cmd::ColumnDefinition>& GetColumns() const { return columns_; }
  const std::list<Record>& GetRecords() const { return records_; }

// TODO: Make its implementation working normal:
  std::string ToString() const;

private:
  cmd::TableDefinition name_;
  std::list<cmd::ColumnDefinition> columns_;
  std::list<Record> records_;

// TODO: Create it in constructor
  se::MetaData meta_;
};

} //namespace sql