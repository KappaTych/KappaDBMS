#pragma once

#include "Instruction.hpp"


namespace cmd {

class DropTrigger : public Instruction
{
public:
  DropTrigger() : Instruction(DROP_TRIGGER) {}
};

} // namespace cmd