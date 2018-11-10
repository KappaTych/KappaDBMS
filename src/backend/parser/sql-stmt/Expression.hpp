#pragma once

#include "Instruction.hpp"


namespace cmd {

enum OperationType
{
  Plus,
  Minus,
  Multiply,
  Division,
};

class Expression : public Instruction
{
public:
  Expression();
  explicit Expression(OperationType t, Literal a, Literal b);
  virtual ~Expression() = default;

  const OperationType operation() const { return operation_; }

private:
  const OperationType operation_;

  Literal left_;
  Literal right_;
};

} // namespace cmd