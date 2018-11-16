#pragma once

#include "Instruction.hpp"
#include "Literal.hpp"


namespace cmd {

class ColumnDefinition : public Instruction
{
public:
  ColumnDefinition() = default;
  ColumnDefinition(const std::string& s, cmd::LiteralType t)
    : Instruction(COLUMN_DEF), name_(s), type_(t) {}

  const ColumnDefinition& Dispatch() const override { return *this; }

  const ColumnDefinition& Dispatch() const override { return *this; }

public: // It's not an error
  std::string name_;
  cmd::LiteralType type_;
};

} // namespace cmd