#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <json.hpp>
#include <fifo_map.hpp>
#include <parser/sql.hpp>
#include <storage/StorageEngine.hpp>

#include "Field.hpp"

namespace sql
{

using json = nlohmann::json;

std::string to_string(cmd::LiteralType t);

class Table
{
public:
  using Column = std::pair<std::string, cmd::LiteralType>;
  using Record = std::vector< std::shared_ptr<Field> >;

public:
  Table() { }

  explicit Table(
      cmd::TableDefinition name
    ) : name_(name) { }

  explicit Table(
      cmd::TableDefinition name,
      std::list<Column> columns
    ) : name_(name),
        columns_(columns) { }

  explicit Table(
      cmd::TableDefinition name,
      std::list<Column> columns,
      std::list<Record> records
    ) : name_(name),
        columns_(columns),
        records_(records) { }

  explicit Table(
      std::list<Column> columns,
      std::list<Record> records
    ) : columns_(columns),
        records_(records) { }

  void AddColumn(Column column);
  void InsertRecord(Record record);
  void DeleteRecord(int index);

  const std::list<Column>& GetColumns() const { return columns_; }
  const std::list<Record>& GetRecords() const { return records_; }

// TODO: Make its implementation working normal:
  std::string ToString() const;

public:
  Table operator+() const;
  Table operator-() const;
  Table operator+(const Table& operand) const;
  Table operator-(const Table& operand) const;
  Table operator*(const Table& operand) const;
  Table operator/(const Table& operand) const;
  Table operator%(const Table& operand) const;

  bool operator^(const Table& operand) const;
  bool operator&&(const Table& operand) const;
  bool operator||(const Table& operand) const;
  bool operator!() const;

  bool operator==(const Table& operand) const;
  bool operator!=(const Table& operand) const;
  bool operator>(const Table& operand) const;
  bool operator<(const Table& operand) const;
  bool operator>=(const Table& operand) const;
  bool operator<=(const Table& operand) const;

  cmd::TableDefinition name_;

private:
  std::list<Column> columns_;
  std::list<Record> records_;
};


void to_json(json& j, const Table& t);
void from_json(const json& j, Table& t);

} //namespace sql