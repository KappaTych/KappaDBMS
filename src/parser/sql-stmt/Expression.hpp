#pragma once

#include "Instruction.hpp"


namespace cmd {

class Expression : public Instruction
{
public:
  Expression() : Instruction(EXPRESSION) {}
  Expression(InstructionType t) : Instruction(t) {}

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

  ~Expression() = default;
};

} // namespace cmd