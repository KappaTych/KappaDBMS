#pragma once

#include "Instruction.hpp"


namespace cmd {

class Expression : public Instruction
{
public:
  Expression() : Instruction(EXPRESSION), {}

  ~Expression() = default;
};

} // namespace cmd