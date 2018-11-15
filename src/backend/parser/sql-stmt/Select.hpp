#pragma once

#include "Instruction.hpp"


namespace cmd {

class Select : public Instruction
{
public:
  Select() : Instruction(SELECT) {}
  const Select& Dispatch() const override { return *this; }
};

} // namespace cmd