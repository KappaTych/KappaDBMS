#pragma once

#include "Instruction.hpp"


namespace cmd {

class DropView : public Instruction
{
public:
  DropView() : Instruction(DROP_VIEW) {}
};

} // namespace cmd