#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"
#include "ColumnDefinition.hpp"

namespace cmd {

class CreateTable : public Instruction
{
public:
  CreateTable(TableDefinition& t, std::list<ColumnDefinition>& c)
      : Instruction(CREATE_TABLE),
        table_(t),
        columns_(c) {}

  const CreateTable& Dispatch() const override { return *this; }

public: // It's not an error
  TableDefinition table_;
  std::list<ColumnDefinition> columns_;
};

} // namespace cmd