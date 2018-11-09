#pragma once

namespace sql {

enum class ExprType {
	ExprLiteralDouble,
	ExprLiteralInt,
	ExprLiteralNull,
	ExprLiteralString,
  ExprLiteralBool,
};

class Expression {
 public:
  Expression(ExprType t) : type(t) {};
  ~Expression() = default;

  ExprType type;

  int64_t ival;
  double fval;
  bool bval;
  std::string strval;

  static Expression *makeLiteral(int64_t);
  static Expression *makeLiteral(double);
  static Expression *makeLiteral(bool);
  static Expression *makeLiteral(std::string);
  static Expression *makeNullLiteral();

};

} // namespace sql