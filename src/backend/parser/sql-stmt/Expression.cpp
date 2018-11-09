#include "Expression.hpp"


namespace cmd {

Expression* Expression::makeLiteral(int64_t val)
{
  auto e = new Expression(Int);
  e.ival = val;
  return e;
}

Expression* Expression::makeLiteral(double val)
{
  auto e = new Expression(Double);
  e.fval = val;
  return e;
}

Expression* Expression::makeLiteral(bool val)
{
  auto e = new Expression(Bool);
  e.bval = val;
  return e;
}

Expression* Expression::makeLiteral(std::string val)
{
  auto e = new Expression(String);
  e.strval = val;
  return e;
}

} // namespace cmd