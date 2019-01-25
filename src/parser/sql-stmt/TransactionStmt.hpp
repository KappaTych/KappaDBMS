#pragma once

#include "Instruction.hpp"

namespace  cmd {

class BeginTransaction : public Instruction {
public:
  BeginTransaction() : Instruction(BEGIN_) {}
  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }
};

class Commit : public Instruction {
public:
  Commit() : Instruction(COMMIT) {}
  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }
};

class Rollback : public Instruction {
public:
  Rollback() : Instruction(ROLLBACK) {}
  sql::Table* Accept(sql::DriverBase& d) override { return d.Execute(*this); }
};

} // cmd
