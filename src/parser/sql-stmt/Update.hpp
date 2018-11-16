#pragma once

#include "Instruction.hpp"


namespace cmd {

class Update : public Instruction
{
public:
  Update() : Instruction(UPDATE) {}
  const Update& Dispatch() const override { return *this; }
};

} // namespace cmd