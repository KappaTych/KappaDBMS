#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"


namespace cmd {

class CreateTable : public Instruction
{
public:
  CreateTable(TableDefinition& t)
      : Instruction(CREATE_TABLE),
        table_(t) {}


  const Instruction& Dispatch() const override { return *this; }

public: // It's not an error
  TableDefinition& table_;
  std::list<Instruction*> columns_;
};

} // namespace cmd