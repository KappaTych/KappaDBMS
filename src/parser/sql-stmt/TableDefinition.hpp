#pragma once 

#include "Instruction.hpp"

namespace cmd {

class TableDefinition : public Instruction
{
public:
  TableDefinition(const std::string& n = "temp", const std::string& d = "default", const std::string& s = "public")
      : Instruction(TABLE_DEF),
        schema_(s),
        name_(n),
        database_(d) {}

  const TableDefinition& Dispatch() const override { return *this; }

  std::string ToString() const {
    return name_;
    // return database_ + ':' + schema_ + ':' + name_;
  }

  //TODO: tostring method
public: // It's not an error
  std::string database_;
  std::string schema_;
  std::string name_;
};

} // namespace cmd