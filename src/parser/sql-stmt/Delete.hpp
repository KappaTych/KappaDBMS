#pragma once

#include "Instruction.hpp"
#include "TableDefinition.hpp"
#include "Expression.hpp"

namespace cmd {

class Delete : public Instruction
{
public:
  Delete(TableDefinition table, ptr_Expression where)
    : Instruction(DELETE),
      table_(std::move(table)), where_(std::move(where)) {}
  ~Delete() = default;

  const Delete& Dispatch() const override { return *this; }

public:
  TableDefinition table_;
  ptr_Expression where_;
};

} // namespace cmd