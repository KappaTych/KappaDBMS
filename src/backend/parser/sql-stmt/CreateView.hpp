#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateView : public Instruction
{
public:
  CreateView() : Instruction(CREATE_VIEW) {}
};

} // namespace cmd