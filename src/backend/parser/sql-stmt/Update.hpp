#pragma once

#include "Instruction.hpp"


namespace cmd {

class Update : public Instruction
{
public:
  Update() : Instruction(UPDATE) {}
  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd