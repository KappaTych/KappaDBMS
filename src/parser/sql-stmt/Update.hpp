#pragma once

#include "TableDefinition.hpp"
#include "Instruction.hpp"


namespace cmd {

class Update : public Instruction
{
public:
  Update(TableDefinition table, std::list<cmd::UpdateClause> setList,
         ptr_Expression where = nullptr)
    : Instruction(UPDATE), table_(table),  setList_(),
      where_(where) {
    for (auto& e : setList) {
        setList_.emplace_back(e.update_clause);
    }
  }

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

public:
  TableDefinition table_;
  ptr_Expression where_;
  std::list<std::pair<Column, ptr_Expression>> setList_;

};

} // namespace cmd