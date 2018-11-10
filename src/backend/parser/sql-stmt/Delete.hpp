#pragma once

#include "Instruction.hpp"


namespace cmd {

class Delete : public Instruction
{
public:
  Delete() : Instruction(DELETE) {}
  ~Delete() = default;

  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd