#pragma once

#include "Instruction.hpp"


namespace cmd {

class Insert : public Instruction
{
public:
  Insert() = default;
  Insert(cmd::TableDefinition table, std::list<cmd::Literal> values)
    : Instruction(INSERT), table_(table), values_(values), into_() {}
  Insert(cmd::TableDefinition table,
         std::list<cmd::Literal> values, std::list<cmd::Column> into_)
    : Instruction(INSERT), table_(table), values_(values), into_(into_) {}

  const Insert& Dispatch() const override { return *this; }

public:
  cmd::TableDefinition table_;
  std::list<cmd::Column>  into_;
  std::list<cmd::Literal> values_;
};

} // namespace cmd