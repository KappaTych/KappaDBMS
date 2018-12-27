#pragma once

#include "Expression.hpp"

namespace cmd {

class Column : public Expression {
 public:
  Column() = default;
  Column(const std::string& name, const std::string& table, const std::string& s)
      :  name_(name), table_(table), schema_(s) {}
  Column(const std::string& name, const std::string& table) :  name_(name), table_(table) {}
  Column(const std::string& name) : name_(name){}

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

 private:
  std::string schema_;
  std::string table_;
  std::string name_;
};

} // namespace cmd