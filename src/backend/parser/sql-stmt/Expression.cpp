#include "Expression.h"


sql::Expression *sql::Expression::makeLiteral(int64_t val) {
	auto e = new sql::Expression(sql::ExprLiteralInt);
	e.ival = val;
	return e;
}

sql::Expression *sql::Expression::makeLiteral(double val) {
	auto e = new sql::Expression(sql::ExprLiteralDouble);
	e.fval = val;
	return e;
}
sql::Expression *sql::Expression::makeLiteral(bool val) {
	auto e = new sql::Expression(sql::ExprLiteralBool);
	e.bval = val;
	return e;
}

sql::Expression *sql::Expression::makeLiteral(std::string val) {
	auto e = new sql::Expression(sql::ExprLiteralString);
	e.strval = val;
	return e;
}

sql::Expression *sql::Expression::makeNullLiteral() {
	auto e = new sql::Expression(sql::ExprLiteralNull);
	return e;
}