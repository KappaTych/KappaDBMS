#pragma once

namespace cmd
{

class Instruction;
class Literal;
class Operation;
class UnaryOperation;
class BinaryOperation;
class CreateTable;
class DropTable;
class Select;
class Insert;
class ShowCreateTable;
class TableDefinition;
class Update;
class Delete;
class Expression;
class Column;
class ColumnDefinition;
class CreateTable;
class BeginTransaction;
class Commit;
class Rollback;

} // namespace cmd

namespace sql
{

class Table;

class DriverBase
{
public:
  virtual Table* Execute(const cmd::Instruction&) = 0;
  virtual Table* Execute(const cmd::Literal&) = 0;
  virtual Table* Execute(const cmd::Expression&) = 0;
  virtual Table* Execute(const cmd::Operation&) = 0;
  virtual Table* Execute(const cmd::UnaryOperation&) = 0;
  virtual Table* Execute(const cmd::BinaryOperation&) = 0;
  virtual Table* Execute(const cmd::ShowCreateTable&) = 0;
  virtual Table* Execute(const cmd::TableDefinition&) = 0;
  virtual Table* Execute(const cmd::ColumnDefinition&) = 0;
  virtual Table* Execute(const cmd::CreateTable&) = 0;
  virtual Table* Execute(const cmd::DropTable&) = 0;
  virtual Table* Execute(const cmd::Select&) = 0;
  virtual Table* Execute(const cmd::Insert&) = 0;
  virtual Table* Execute(const cmd::Update&) = 0;
  virtual Table* Execute(const cmd::Delete&) = 0;
  virtual Table* Execute(const cmd::Column&) = 0;
  virtual Table* Execute(const cmd::BeginTransaction&) = 0;
  virtual Table* Execute(const cmd::Commit&) = 0;
  virtual Table* Execute(const cmd::Rollback&) = 0;
};

} // namespace sql