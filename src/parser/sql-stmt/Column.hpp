#pragma once

#include "Expression.hpp"

namespace cmd {

class Column : public Expression {
 public:
  Column() = default;
  Column(const std::string& name, const std::string& table, const std::string& s)
    : Expression(COLUMN), name_(name), table_(table), schema_(s) { }
  Column(const std::string& name, const std::string& table)
    : Expression(COLUMN), name_(name), table_(table) { }
  Column(const std::string& name)
    : Expression(COLUMN), name_(name) { }

  std::string ToString() override { return name_; }

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

 public:
  std::string schema_;
  std::string table_;
  std::string name_;
};

} // namespace cmd