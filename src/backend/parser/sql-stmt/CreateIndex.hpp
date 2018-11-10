#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateIndex : public Instruction
{
public:
  CreateIndex() : Instruction(CREATE_INDEX) {}
};

} // namespace cmd