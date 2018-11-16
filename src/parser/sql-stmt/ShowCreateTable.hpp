#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"

namespace cmd {

class ShowCreateTable : public Instruction
{
public:
  ShowCreateTable() = default;
  explicit ShowCreateTable(TableDefinition table)
    : Instruction(SHOW_CREATE_TABLE), table_(std::move(table)) {}

  const ShowCreateTable& Dispatch() const override { return *this; }

public:
  cmd::TableDefinition table_;
};

} // namespace cmd