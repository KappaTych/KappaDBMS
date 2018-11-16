#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"


namespace cmd {

class DropTable : public Instruction {
public:
  DropTable() = default;
  explicit DropTable(cmd::TableDefinition table) : Instruction(DROP_TABLE), table_(std::move(table)) {}
  ~DropTable() override = default;

  const DropTable& Dispatch() const override { return *this; }

public:
  cmd::TableDefinition table_;
};

} // namespace cmd