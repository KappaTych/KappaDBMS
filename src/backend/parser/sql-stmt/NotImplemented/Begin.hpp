#pragma once

#include "Instruction.hpp"


namespace cmd {

class Begin : public Instruction
{
public:
  Begin() : Instruction(BEGIN) {}
};

} // namespace cmd