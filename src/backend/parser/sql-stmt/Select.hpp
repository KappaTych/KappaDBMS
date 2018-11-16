#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"
#include "ColumnDefinition.hpp"
#include "Expression.hpp"

namespace cmd {

class Select : public Instruction {
 public:
  Select() = default;

  explicit Select(TableDefinition table,
                  std::shared_ptr<cmd::Expression> whereExpr = nullptr)
    : Instruction(InstructionType::SELECT_ALL),
      table_(std::move(table)), whereExpr_(std::move(whereExpr)) {}

  explicit Select(TableDefinition table,
                  std::list<std::shared_ptr<cmd::Expression>> columnDef,
                  std::shared_ptr<cmd::Expression> whereExpr = nullptr)
    : Instruction(InstructionType::SELECT),
      table_(std::move(table)), columnDef_(std::move(columnDef)),
      whereExpr_(std::move(whereExpr)) {}

  const Select& Dispatch() const override { return *this; }

 public:
  cmd::TableDefinition table_;
  std::list<std::shared_ptr<cmd::Expression>> columnDef_;
  std::shared_ptr<cmd::Expression> whereExpr_;
};

} // namespace cmd