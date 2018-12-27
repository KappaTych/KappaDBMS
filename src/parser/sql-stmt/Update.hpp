#pragma once

#include "TableDefinition.hpp"
#include "Instruction.hpp"


namespace cmd {

class Update : public Instruction
{
public:
  Update(TableDefinition table, std::list<std::pair<Column, ptr_Expression>> setList,
         ptr_Expression where = nullptr)
    : Instruction(UPDATE), table_(table),  setList_(setList),
      where_(where) {}

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

public:
  TableDefinition table_;
  ptr_Expression where_;
  std::list<std::pair<Column, ptr_Expression>> setList_;

};

} // namespace cmd