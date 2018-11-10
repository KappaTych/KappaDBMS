#pragma once

#include "Instruction.hpp"


namespace cmd {

enum class LiteralType
{
  NONE,
  BOOL,
  INT,
  DOUBLE,
  STRING,
};

class Literal : public Instruction
{
public:
  Literal() : Instruction(LITERAL), valueType_(LiteralType::NONE) {}
  explicit Literal(bool v) : Instruction(LITERAL), valueType_(LiteralType::BOOL), ival_(v) {}
  explicit Literal(int64_t v) : Instruction(LITERAL), valueType_(LiteralType::INT), fval_(v) {}
  explicit Literal(double v) : Instruction(LITERAL), valueType_(LiteralType::DOUBLE), bval_(v) {}
  explicit Literal(std::string v) : Instruction(LITERAL), valueType_(LiteralType::STRING), strval_(v) {}
  virtual ~Literal() = default;

  const LiteralType valueType() const { return valueType_; }
  const Instruction& Dispatch() const override { return *this; };

private:
  const LiteralType valueType_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;
};

} // namespace cmd