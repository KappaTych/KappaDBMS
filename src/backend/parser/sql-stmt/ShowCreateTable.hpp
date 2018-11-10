#pragma once

#include "Instruction.hpp"


namespace cmd {

class ShowCreateTable : public Instruction
{
public:
  ShowCreateTable() : Instruction(SHOW_CREATE_TABLE) {}
  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd