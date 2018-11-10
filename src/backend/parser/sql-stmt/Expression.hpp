#pragma once

#include "Instruction.hpp"


namespace cmd {

enum OperationType
{
  Double,
  Int,
  Null,
  String,
  Bool,

  Plus,
  Minus,
  Multiply,
  Division,
};

class Expression : public Instruction
{
public:
  Expression() : operation_(Null) {}
  explicit Expression(OperationType t) : Instruction(EXPRESSION), operation_(t) {}
  virtual ~Expression() = default;

  static Expression* makeLiteral(int64_t);
  static Expression* makeLiteral(double);
  static Expression* makeLiteral(bool);
  static Expression* makeLiteral(std::string);

  const OperationType operation() const { return operation_; }

private:
  const OperationType operation_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;

  Expression* left_;
  Expression* right_;
};

} // namespace cmd