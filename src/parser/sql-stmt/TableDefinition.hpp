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

  const TableDefinition& Dispatch() const override { return *this; }

  std::string ToString() const {
    return name_;
    // return database_ + ':' + schema_ + ':' + name_;
  }

  //TODO: tostring method
public: // It's not an error
  std::string schema_;
  std::string name_;
};

} // namespace cmd