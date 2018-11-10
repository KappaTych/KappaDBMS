#pragma once

#include "Instruction.hpp"


namespace cmd {

class Insert : public Instruction
{
public:
  Insert() : Instruction(INSERT) {}
  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd