#pragma once

#include "Instruction.hpp"


namespace cmd {

class Select : public Instruction
{
public:
  Select() : Instruction(SELECT) {}
  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd