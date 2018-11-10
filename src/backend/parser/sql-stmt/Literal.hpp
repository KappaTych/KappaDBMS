#pragma once

#include "Instruction.hpp"


namespace cmd {

enum class LiteralType
{
  Double,
  Int,
  Null,
  String,
  Bool,
};

class Literal : public Instruction
{
public:
  Literal() : Instruction(LITERAL), operation_(Null) {}
  explicit Literal(LiteralType t) : operation_(t) {}
  virtual ~Literal() = default;

  static Literal* makeLiteral(int64_t);
  static Literal* makeLiteral(double);
  static Literal* makeLiteral(bool);
  static Literal* makeLiteral(std::string);

  const LiteralType operation() const { return operation_; }

private:
  const LiteralType operation_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;

  Literal* left_;
  Literal* right_;
};

} // namespace cmd