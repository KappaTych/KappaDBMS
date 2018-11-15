#pragma once

#include "Instruction.hpp"


namespace cmd {

class ShowCreateTable : public Instruction
{
public:
  ShowCreateTable() : Instruction(SHOW_CREATE_TABLE) {}
  const ShowCreateTable& Dispatch() const override { return *this; }

public:// It's not an error
  TableDefinition table_;
};

} // namespace cmd