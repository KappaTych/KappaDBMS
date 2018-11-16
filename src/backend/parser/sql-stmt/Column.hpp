#pragma once

#include "Expression.hpp"

namespace cmd {

class Column : public Expression {
 public:
  Column() = delete;
  Column(const std::string& name, const std::string& table, const std::string& s)
      :  name_(name), table_(table), schema_(s) {}
  Column(const std::string& name, const std::string& table) :  name_(name), table_(table) {}
  Column(const std::string& name) : name_(name){}

  const Column &Dispatch() const override { return *this; }

 private:
  std::string schema_;
  std::string table_;
  std::string name_;
};

} // namespace cmd