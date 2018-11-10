#pragma once

#include "Instruction.hpp"
#include "Literal.hpp"


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
  Expression() : Instruction(EXPRESSION), operation_(Null) {};
  explicit Expression(OperationType t, Literal a, Literal b)
    : Expression(),
      operation_(t),
      left_(a),
      right_(b) {}

  virtual ~Expression() = default;

  const OperationType operation() const { return operation_; }

private:
  const OperationType operation_;

  Literal left_;
  Literal right_;
};

} // namespace cmd