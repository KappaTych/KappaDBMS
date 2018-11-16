#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"
#include "ColumnDefinition.hpp"

namespace cmd {

class CreateTable : public Instruction
{
public:
  CreateTable(TableDefinition t, std::list<cmd::ColumnDefinition> columns)
    : Instruction(CREATE_TABLE), table_(std::move(t)), columns_(std::move(columns)) {}

  const CreateTable& Dispatch() const override { return *this; }

public: // It's not an error
  TableDefinition table_;
  std::list<cmd::ColumnDefinition> columns_;
};

} // namespace cmd