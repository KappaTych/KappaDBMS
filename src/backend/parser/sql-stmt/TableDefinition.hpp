#pragma once 

#include "Instruction.hpp"


namespace cmd {

class TableDefinition : public Instruction
{
public:
  explicit TableDefinition(std::string n, std::string s = "public")
      : Instruction(TABLE_DEF), schema_(std::move(s)), name_(std::move(n)) {}

  TableDefinition() = default;

  const TableDefinition& Dispatch() const override { return *this; }

public: // It's not an error
  std::string schema_;
  std::string name_;
};

} // namespace cmd