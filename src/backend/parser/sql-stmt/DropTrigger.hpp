#pragma once

#include "Instruction.hpp"


namespace cmd {

class CreateTable : public Instruction
{
public:
  CreateTable() : Instruction(CREATE_TABLE) {}
};

} // namespace cmd