#pragma once

#include "Instruction.hpp"


namespace cmd {

class DropIndex : public Instruction
{
public:
  DropIndex() : Instruction(DROP_INDEX) {}
};

} // namespace cmd