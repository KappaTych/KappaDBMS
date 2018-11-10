#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"


namespace cmd {

enum class OperationType
{
  INVALID,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  MOD,
  LESS,
  GREATER,
  EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  NOT,
  AND,
  OR,
  XOR,
  FUNCTION,
};

class Operation : public Expression
{
public:
  Operation() : Expression(OPERATION), operation_(OperationType::INVALID) {}
  explicit Operation(OperationType t, Expression a, Expression b)
    : Expression(),
      operation_(t),
      left_(a),
      right_(b) {}

  ~Operation() = default;

  const Operation& Dispatch() const override { return *this; }

  const OperationType operation() const { return operation_; }
  const Expression& left() const { return left_; }
  const Expression& right() const { return right_; }

private:
  const OperationType operation_;

  Expression left_;
  Expression right_;
};

} // namespace cmd