#pragma once

#include "Instruction.hpp"


namespace cmd {

class Insert : public Instruction
{
public:
  Insert() : Instruction(INSERT) {}
  const Insert& Dispatch() const override { return *this; }
};

} // namespace cmd