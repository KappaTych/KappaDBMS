#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateTrigger : public Instruction
{
public:
  CreateTrigger() : Instruction(CREATE_TRIGGER) {}
};

} // namespace cmd