#include "Literal.hpp"


namespace cmd {

Literal::Literal() : Instruction(LITERAL), valueType_(LiteralType::NULL) {}
Literal::Literal(bool v) : Literal(), valueType_(LiteralType::BOOL), ival_(v) {}
Literal::Literal(int64_t v) : Literal(), valueType_(LiteralType::INT), fval_(v) {}
Literal::Literal(double v) : Literal(), valueType_(LiteralType::DOUBLE), bval_(v) {}
Literal::Literal(std::string v) : Literal(), valueType_(LiteralType::STRING), strval_(v) {}

} // namespace cmd