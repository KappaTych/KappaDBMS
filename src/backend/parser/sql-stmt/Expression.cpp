#include "Expression.hpp"


namespace cmd {

Expression* Expression::makeLiteral(int64_t val)
{
  auto e = new Expression(Int);
  e->ival_ = val;
  return e;
}

Expression* Expression::makeLiteral(double val)
{
  auto e = new Expression(Double);
  e->fval_ = val;
  return e;
}

Expression* Expression::makeLiteral(bool val)
{
  auto e = new Expression(Bool);
  e->bval_ = val;
  return e;
}

Expression* Expression::makeLiteral(std::string val)
{
  auto e = new Expression(String);
  e->strval_ = val;
  return e;
}

} // namespace cmd