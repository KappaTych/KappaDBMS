#pragma once

#include "Instruction.hpp"


namespace cmd {

class Expression : public Instruction
{
public:
  Expression() : Instruction(EXPRESSION) {}
  Expression(InstructionType t) : Instruction(t) {}

  const Expression& Dispatch() const override { return *this; }

  ~Expression() = default;
};

} // namespace cmd