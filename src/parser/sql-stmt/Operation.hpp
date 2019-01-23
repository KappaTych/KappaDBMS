#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"
#include "Select.hpp"
#include "Column.hpp"

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
  XOR,
  AND,
  OR,
  IS,
  IN,

};

using ptr_Expression = std::shared_ptr<Expression>;
using ptr_update_clause = std::shared_ptr<std::pair<cmd::Column, ptr_Expression>>;
using column_type = std::pair<cmd::LiteralType, std::string>;

// for parser only
class UpdateClause {
public:
    UpdateClause(cmd::Column c, cmd::ptr_Expression e, std::string r)
        : update_clause(std::make_pair(c, e)), raw(r) {}
    UpdateClause() = default;
    UpdateClause& operator=(const UpdateClause &) = default;

    std::pair<cmd::Column, cmd::ptr_Expression> update_clause;
    std::string raw;
};

class Operation : public Expression
{
public:
  Operation() = default;
  explicit Operation(OperationType t) : Expression(OPERATION), operation_(t) {}
  ~Operation() = default;

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

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

  std::string ToString() { return operator_->ToString(); }

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

public:
  ptr_Expression operator_;
};

class BinaryOperation : public Operation
{
public:
  BinaryOperation() = delete;
  explicit BinaryOperation(OperationType type, ptr_Expression left, ptr_Expression right)
    : Operation(type), left_(std::move(left)), right_(std::move(right)) {}

  std::string ToString() { return "(" + left_->ToString() + ", " +  right_->ToString() + ")"; }

  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }

public:
  ptr_Expression left_, right_;
};



} // namespace cmd