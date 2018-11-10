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
  Literal() : Expression(LITERAL), valueType_(LiteralType::NONE) {}
  explicit Literal(bool v) : Expression(LITERAL), valueType_(LiteralType::BOOL), ival_(v) {}
  explicit Literal(int64_t v) : Expression(LITERAL), valueType_(LiteralType::INT), fval_(v) {}
  explicit Literal(double v) : Expression(LITERAL), valueType_(LiteralType::DOUBLE), bval_(v) {}
  explicit Literal(std::string v) : Expression(LITERAL), valueType_(LiteralType::STRING), strval_(v) {}
  
  ~Literal() = default;

  const Literal& Dispatch() const override { return *this; }

  const LiteralType valueType() const { return valueType_; }

  std::string value() const
  {
    switch (valueType_) {
      case LiteralType::NONE:   return "";
      case LiteralType::BOOL:   return (bval_ ? "true" : "false");
      case LiteralType::INT:    return std::to_string(fval_);
      case LiteralType::DOUBLE: return std::to_string(ival_);
      case LiteralType::STRING: return strval_;
    }
  }

private:
  const LiteralType valueType_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;
};

} // namespace cmd