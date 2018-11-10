#pragma once

#include <list>


namespace cmd {

enum InstructionType
{
  INVALID,
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
  BEGIN,
  ROLLBACK,
  COMMIT,
  INSERT,
  DELETE,
  UPDATE,
  SELECT,
  LITERAL,
  EXPRESSION,
};

class Instruction
{
public:
  Instruction() : type_(INVALID) {}
  explicit Instruction(InstructionType type) : type_(type) {}
  virtual ~Instruction() = default;

  const InstructionType type() const { return type_; }

private:
  const InstructionType type_;
};

} // namespace cmd