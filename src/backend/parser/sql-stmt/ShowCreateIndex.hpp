#pragma once

#include "Instruction.hpp"


namespace cmd {

class ShowCreateIndex : public Instruction
{
public:
  ShowCreateIndex() : Instruction(SHOW_CREATE_INDEX) {}
};

} // namespace cmd