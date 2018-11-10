#pragma once

#include "Instruction.hpp"


namespace cmd {

enum class LiteralType
{
  NULL,
  BOOL,
  INT,
  DOUBLE,
  STRING,
};

class Literal : public Instruction
{
public:
  Literal();
  explicit Literal(bool v);
  explicit Literal(int64_t v);
  explicit Literal(double v);
  explicit Literal(std::string v);
  virtual ~Literal() = default;

  const LiteralType valueType() const { return valueType_; }

private:
  const LiteralType valueType_;

  bool bval_;
  double fval_;
  int64_t ival_;
  std::string strval_;
};

} // namespace cmd