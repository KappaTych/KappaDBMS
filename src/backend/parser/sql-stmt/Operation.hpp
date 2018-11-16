#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"
#include "Select.hpp"

#include <vector>

namespace cmd {

enum class OperationType
{
  UNARY_MINUS,
  UNARY_PLUS,
  BIN_NOT,
  NOT,
  ISNULL,

  CONCATENATION,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVISION,
  MOD,
  LEFTSHIFT,
  RIGHTSHIFT,
  BIN_AND,
  BIN_OR,
  LESS,
  GREATER,
  LESS_EQUAL,
  GREATER_EQUAL,
  EQUAL,
  NOT_EQUAL,
  AND,
  OR,
  IS,
  IN,

};

using ptr_Expression = std::shared_ptr<Expression>;

class Operation : public Expression
{
public:
  Operation() = default;
  explicit Operation(OperationType t) : operation_(t) {}
  ~Operation() = default;

//   const Operation& Dispatch() const override { return *this; }

  const OperationType operation() const { return operation_; }
private:
  const OperationType operation_;
};


class UnaryOperation : public Operation
{
public:
  UnaryOperation() = default;
  explicit UnaryOperation(OperationType type, ptr_Expression exp)
    : Operation(type), operator_(std::move(exp)) {}

public:
  ptr_Expression operator_;
};

class BinaryOperation : public Operation
{
public:
  BinaryOperation() = delete;
  explicit BinaryOperation(OperationType type, ptr_Expression left, ptr_Expression right)
    : Operation(type), left_(std::move(left)), right_(std::move(right)) {}

public:
  ptr_Expression left_, right_;
};



} // namespace cmd