#pragma once

#include "Instruction.hpp"


namespace cmd {

class Commit : public Instruction
{
public:
  Commit() : Instruction(COMMIT) {}

};

} // namespace cmd