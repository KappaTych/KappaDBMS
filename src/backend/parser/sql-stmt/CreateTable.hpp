#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateTable : public Instruction
{
public:
  CreateTable() : Instruction(CREATE_TABLE) {}

  Instruction* tableName;
  std::list<Instruction*> args;

  const Instruction& Dispatch() const override { return *this; }
};

} // namespace cmd