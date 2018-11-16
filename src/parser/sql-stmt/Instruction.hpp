#pragma once

#include <list>
#include <memory>
#include <vector>


namespace cmd {

enum InstructionType
{
  INVALID,
  COLUMN_DEF,
  TABLE_DEF,
  CREATE_DATABASE,
  CREATE_SCHEME,
  CREATE_TABLE,
  CREATE_TRIGGER,
  CREATE_VIEW,
  CREATE_USER,
  CREATE_INDEX,
  SHOW_CREATE_DATABASE,
  SHOW_CREATE_SCHEME,
  SHOW_CREATE_TABLE,
  SHOW_CREATE_VIEW,
  SHOW_CREATE_USER,
  SHOW_CREATE_TRIGGER,
  SHOW_CREATE_INDEX,
  DROP_DATABASE,
  DROP_SCHEME,
  DROP_TABLE,
  DROP_VIEW,
  DROP_USER,
  DROP_TRIGGER,
  DROP_INDEX,
  BEGIN_,
  ROLLBACK,
  COMMIT,
  INSERT,
  DELETE,
  UPDATE,
  SELECT_ALL,
  SELECT,
  EXPRESSION,
  LITERAL,
  OPERATION,
};

class Instruction
{
public:
  Instruction() : type_(INVALID) {}
  explicit Instruction(InstructionType type) : type_(type) {}
  virtual ~Instruction() = default;
  const InstructionType type() const { return type_; }
  virtual const Instruction& Dispatch() const = 0;

private:
  InstructionType type_;
};

} // namespace cmd