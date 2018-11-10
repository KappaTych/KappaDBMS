#include "Expression.hpp"


namespace cmd {

Expression::Expression() : Instruction(EXPRESSION), operation_(Null) {}
Expression::Expression(OperationType t, Literal a, Literal b)
    : Expression(),
      operation_(t),
      left_(a),
      right_(b) {}

} // namespace cmd