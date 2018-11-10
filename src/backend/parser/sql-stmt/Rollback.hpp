#pragma once

#include "Instruction.hpp"


namespace cmd {

class Rollback : public Instruction
{
public:
  Rollback() : Instruction(ROLLBACK) {}
};

} // namespace cmd