#pragma once

#include "Instruction.hpp"


namespace cmd {

class DropTable : public Instruction
{
public:
  DropTable() : Instruction(DROP_TABLE) {}
  ~DropTable() = default;

  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd