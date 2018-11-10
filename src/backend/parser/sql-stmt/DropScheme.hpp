#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateScheme : public Instruction
{
public:
  CreateScheme() : Instruction(CREATE_SCHEME) {}
};

} // namespace cmd