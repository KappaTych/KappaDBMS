#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"

// TODO: Make separate files for all compatible types

namespace cmd {

enum class LiteralType
{
  NONE,
  BOOL,
  INT,
  DOUBLE,
  STRING,
};

class Literal : public Expression
{
public:
  Literal() : Instruction(LITERAL), valueType_(LiteralType::NONE) {}
  explicit Literal(bool v) : Instruction(LITERAL), valueType_(LiteralType::BOOL), ival_(v) {}
  explicit Literal(int64_t v) : Instruction(LITERAL), valueType_(LiteralType::INT), fval_(v) {}
  explicit Literal(double v) : Instruction(LITERAL), valueType_(LiteralType::DOUBLE), bval_(v) {}
  explicit Literal(std::string v) : Instruction(LITERAL), valueType_(LiteralType::STRING), strval_(v) {}
  
  ~Literal() = default;

  const Literal& Dispatch() const override { return *this; }

  const LiteralType valueType() const { return valueType_; }

  void value(LiteralType::NONE) const { }
  bool value(LiteralType::BOOL) const { return bval_; }
  double value(LiteralType::INT) const { return fval_; }
  int64_t value(LiteralType::DOUBLE) const { return ival_; }
  std::string value(LiteralType::STRING) const { return strval_; }

private:
  const LiteralType valueType_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;
};

} // namespace cmd