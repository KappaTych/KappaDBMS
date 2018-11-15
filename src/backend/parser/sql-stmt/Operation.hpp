#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"
#include "Select.hpp"

namespace cmd {

enum class OperationType
{
  UNARY_MINUS,
  UNARY_PLUS,
  BIN_NOT,
  NOT,
  COLLATE,
  CAST,
  ISNULL,

  CONCATENATION,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  MOD,
  LEFTSHIFT,
  RIGHTSHIFT,
  BIN_AND,
  BIN_OR,
  LESS,
  GREATER,
  LESS_EQUAL,
  GREATER_EQUAL,
  EQUAL,
  NOT_EQUAL,
  AND,
  OR,
  IS,
  IN,

  LIKE,
  GLOB,
  MATCH,
  REGEXP,

  FUNCTION,

  BETWEEN,

  WHEN,
  WHEN_ELSE,
  EXISTS,

  EXPRESSION_LIST,
};

class Operation : public Expression
{
public:
  Operation() = delete;
//   explicit Operation(OperationType t, const std::vector<Expression>& params)
//     : Expression(),
//       operation_(t),
//       params_(params) {}

//   ~Operation() = default;

//   const Operation& Dispatch() const override { return *this; }

//   const OperationType operation() const { return operation_; }
//   const std::vector<Expression>& params() const { return params_; }

//   void push_back(const Expression& exp) { params_.push_back(exp); }

// private:
//   const OperationType operation_;

//   std::vector<Expression> params_;
};


// class UnaryOperation : public Operation
// {
// public:
//   UnaryOperation() = delete;
//   explicit UnaryOperation(OperationType type, const Expression& exp)
//     : Operation(type, std::vector<Expression>({exp, })) {}

// };

// class BinaryOperation : public Operation
// {
//  public:
//   BinaryOperation() = delete;
//   explicit BinaryOperation(OperationType type, const Expression& left, const Expression& right)
//     : Operation(type, std::vector({left, right, })) {}
// };


// class CollateOperation : public UnaryOperation
// {
// public:
//   CollateOperation() = delete;
//   explicit CollateOperation(const Expression& exp, const std::string& collationName)
//     : UnaryOperation(OperationType::COLLATE, exp), collationName_(collationName) {}

// private:
//   std::string collationName_;
// };

// class CastOperation : public UnaryOperation
// {
// public:
//   CastOperation() = delete;
//   explicit CastOperation(const Expression& exp, const std::string typeName)
//     : UnaryOperation(OperationType::Cast, exp),  typeName_(typeName) {}

// private:
//   std::string typeName_;
// };

// class EmbeddedFunction : public UnaryOperation
// {
// public:
//   EmbeddedFunction() = delete;
//   explicit EmbeddedFunction(OperationType type, const Expression& left, const Expression& right)
//     : UnaryOperation(type, left, right),
//       isWithEscape_(false), escape_() {}

//   explicit EmbeddedFunction(OperationType type, const Expression& left, const Expression& right,
//                             const Expression& escape)
//     : UnaryOperation(type, left, right),
//       isWithEscape_(true), escape_(escape) {}

// private:
//   Expression escape_;
//   bool isWithEscape_;
// };

// class BetweenOperation : public Operation
// {
//  public:
//   BetweenOperation() = delete;
//   BetweenOperation(const Expression& base, const Expression& left, const Expresion& right)
//     : Operation(OperationType::BETWEEN, std::vector<Expression>({base, left, right})) {}
// };

// class WhenOperation : public Operation
// {
// public:
//   WhenOperation() = delete;
//   WhenOperation(const Expresion& whenExp) : Operation(OperationType::WHEN, std::vector<Expression>({whenExp})) {}
//   WhenOperation(const Expresion& whenExp, const Expression& elseExp)
//     : Operation(OperationType::WHEN_ELSE, std::vector<Expression>({whenExp, elseExp})) {}
// };

// class CaseWhenOperation : public WhenOperation
// {
// public:
//   CaseWhenOperation() = delete;
//   CaseWhenOperation(const Expression& base, const Expresion& whenExp)
//     : WhenOperation(whenExp), base_(base) {}
//   WhenOperation(const Expression& base, const Expresion& whenExp, const Expression& elseExp)
//       : WhenOperation(whenExp, elseExp), base_(base) {}


//  private:
//   Expression base_;
// };

// class ExistsOperation : public Operation
// {
// public:
//   ExistsOperation() = delete;
//   ExistsOperation(const Select& s) : Operation(OperationType::EXISTS), selectStm_(s) {}

//  private:
//   Select selectStm_;
// };


// class InListOperation : public Operation
// {
//  public:
//   InListOperation() = delete;
//   InListOperation(std::vector<Expression> expList) : Operation(OperationType::IN, expList) {}
// };


// class InSelectOperation : public Operation
// {
//  public:
//   InSelectOperation() = delete;
//   InSelectOperation(const Select& s) : Operation(OperationType::IN), selectStm_(s) {}

//  private:
//   Select selectStm_;
// };

// class InTableOperation : public Operation
// {
//  public:
//   InTableOperation() = delete;
//   InTableOperation(const std::string& schema, const std::string& name)
//       : Operation(OperationType::In), schema_(schema), name_(name) {}

// private:
//   std::string shema_, name_;
// };

// class Function : public Operation
// {
//  public:
//   Function(const std::string& functionName)
//     : Operation(OperationType::FUNCTION), functionName_(functionName) {}
//   Function(const std::string& functionName, const std::vector<Expression>& params_)
//     : Operation(OperationType::FUNCTION, params), functionName_(functionName) {}

//  private:
//   std::string functionName_;
// };

} // namespace cmd