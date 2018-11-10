#pragma once 

#include "Instruction.hpp"


namespace cmd {

class TableDefinition : public Instruction
{
public:
  TableDefinition(const std::string& n, const std::string& d = "default", const std::string& s = "public")
      : Instruction(TABLE_DEF),
        database_(d),
        schema_(s),
        name_(n) {}

  const Instruction& Dispatch() const override { return *this; }

public: // It's not an error
  std::string database_;
  std::string schema_;
  std::string name_;
};

} // namespace cmd