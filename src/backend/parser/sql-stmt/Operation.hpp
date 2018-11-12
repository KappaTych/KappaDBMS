#pragma once

#include "Instruction.hpp"
#include "Expression.hpp"
#include "Select.hpp"

#include <vector>

namespace cmd {

enum class OperationType
{
  UNARY_MINUS,
  UNARY_PLUS,
  BIN_NOT,
  NOT,
  ISNULL,

  CAST,
  COLLATE,

  CONCATENATION,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVISION,
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

using ptr_Expression = std::shared_ptr<Expression>;

class Operation : public Expression
{
public:
  Operation() = delete;
  explicit Operation(OperationType t) : operation_(t) {}
  explicit Operation(OperationType t, const std::vector<ptr_Expression>& params)
    : Expression(),
      operation_(t),
      params_(params) {}

  ~Operation() = default;

  const Operation& Dispatch() const override { return *this; }

  const OperationType operation() const { return operation_; }
  const std::vector<ptr_Expression>& params() const { return params_; }

private:
  const OperationType operation_;

  std::vector<ptr_Expression> params_;
};


class UnaryOperation : public Operation
{
public:
  UnaryOperation() = delete;
  explicit UnaryOperation(OperationType type, const ptr_Expression& exp)
    : Operation(type, {exp, }) {}

};

class BinaryOperation : public Operation
{
 public:
  BinaryOperation() = delete;
  explicit BinaryOperation(OperationType type, const ptr_Expression& left, const ptr_Expression& right)
    : Operation(type, {left, right, }) {}
};


class CollateOperation : public UnaryOperation
{
public:
  CollateOperation() = delete;
  explicit CollateOperation(const ptr_Expression& exp, const std::string& collationName)
    : UnaryOperation(OperationType::COLLATE, exp), collationName_(collationName) {}

private:
  std::string collationName_;
};

class CastOperation : public UnaryOperation
{
public:
  CastOperation() = delete;
  explicit CastOperation(const ptr_Expression& exp, const std::string typeName)
    : UnaryOperation(OperationType::CAST, exp),  typeName_(typeName) {}

private:
  std::string typeName_;
};

class EmbeddedFunction : public BinaryOperation
{
public:
  EmbeddedFunction() = delete;
  explicit EmbeddedFunction(OperationType type, const ptr_Expression& left, const ptr_Expression& right)
    : BinaryOperation(type, left, right),
      isWithEscape_(false), escape_() {}

  explicit EmbeddedFunction(OperationType type, const ptr_Expression& left, const ptr_Expression& right,
                            const ptr_Expression& escape)
    : BinaryOperation(type, left, right),
      isWithEscape_(true), escape_(escape) {}

private:
  ptr_Expression escape_;
  bool isWithEscape_;
};

class BetweenOperation : public Operation
{
 public:
  BetweenOperation() = delete;
  BetweenOperation(const ptr_Expression& base, const ptr_Expression& left, const ptr_Expression& right)
    : Operation(OperationType::BETWEEN, {base, left, right}) {}
};

class WhenOperation : public Operation
{
public:
  WhenOperation() = delete;
  WhenOperation(const ptr_Expression& whenExp) : Operation(OperationType::WHEN, {whenExp}) {}
  WhenOperation(const ptr_Expression& whenExp, const ptr_Expression& elseExp)
    : Operation(OperationType::WHEN_ELSE, {whenExp, elseExp}) {}
};

class CaseWhenOperation : public WhenOperation
{
public:
  CaseWhenOperation() = delete;
  CaseWhenOperation(const ptr_Expression& base, const ptr_Expression& whenExp)
    : WhenOperation(whenExp), base_(base) {}
  CaseWhenOperation(const ptr_Expression& base, const ptr_Expression& whenExp, const ptr_Expression& elseExp)
      : WhenOperation(whenExp, elseExp), base_(base) {}


 private:
  ptr_Expression base_;
};

class ExistsOperation : public Operation
{
public:
  ExistsOperation() = delete;
  ExistsOperation(const Select& s) : Operation(OperationType::EXISTS), selectStm_(s) {}

 private:
  Select selectStm_;
};


class InListOperation : public Operation
{
 public:
  InListOperation() = delete;
  InListOperation(const std::vector<ptr_Expression>& expList) : Operation(OperationType::IN, expList) {}
};


class InSelectOperation : public Operation
{
 public:
  InSelectOperation() = delete;
  InSelectOperation(const Select& s) : Operation(OperationType::IN), selectStm_(s) {}

 private:
  Select selectStm_;
};

class InTableOperation : public Operation
{
 public:
  InTableOperation() = delete;
  InTableOperation(const std::string& schema, const std::string& name)
      : Operation(OperationType::IN), schema_(schema), name_(name) {}

private:
  std::string schema_, name_;
};

class Function : public Operation
{
 public:
  Function(const std::string& functionName)
    : Operation(OperationType::FUNCTION), functionName_(functionName) {}
  Function(const std::string& functionName, const std::vector<ptr_Expression>& params)
    : Operation(OperationType::FUNCTION, params), functionName_(functionName) {}

 private:
  std::string functionName_;
};

} // namespace cmd