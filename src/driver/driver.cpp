#include "driver.hpp"

// TODO: explore for memory leaks (pointers)

namespace sql
{

thread_local std::unordered_map<std::string, std::pair<sql::Table::Column, sql::Table::Record>> Driver::capture = {};

cmd::LiteralType LiteralTypeFromStr(const std::string str)
{
  if (str == "INTEGER")
    return cmd::LiteralType::INTEGER;
  else if (str == "DOUBLE")
    return cmd::LiteralType::DOUBLE;
  else if (str == "TEXT")
    return cmd::LiteralType::TEXT;
  else if (str == "BOOL")
    return cmd::LiteralType::BOOL;
  return cmd::LiteralType::NONE;
}

std::string Driver::RunQuery(const std::string query)
{
  auto& parser = Parser::Instance();
  auto instructions = parser.Process(query);
  std::vector<Table> tables;
  for (auto& instruction : instructions) {
    Table* t = instruction->Accept(*this);
    t->name_ = cmd::TableDefinition(instruction->GetRaw());
    tables.push_back(*t);
    delete(t);
  }
  json result;
  result["code"] = 1;
  result["result"] = tables;
  return result.dump();
}

Table* Driver::Execute(const cmd::Instruction& instruction)
{
  throw std::logic_error("DriverError: Invalid instruction. Couldn't find child instruction");
}

Table* Driver::Execute(const cmd::Expression&)
{
  throw std::logic_error("DriverError: Call to base expression");
}

Table* Driver::Execute(const cmd::Operation& instruction)
{
  throw std::logic_error("DriverError: Call to base operation");
}

Table* Driver::Execute(const cmd::TableDefinition& instruction)
{
  return new Table(instruction);
}

Table* Driver::Execute(const cmd::CreateTable& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  std::string name = instruction.table_.ToString();
  if (storage.HasMetaData(name)) {
      throw std::logic_error("DriverError: Table already exist");
  }
  se::MetaData& meta = storage.CreateData(name);
  for (auto& col : instruction.columns_) {
      meta.Add(col.name_, to_string(col.type_));
  }

  se::size_t size = 0;
  for (auto& row : meta.data().at("public").items()) {
      size += mapping[row.value()];
  }
  meta.Add("size", size, "private");
  storage.Flush();

  return new Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<BoolField>(true)} });
}

Table* Driver::Execute(const cmd::DropTable& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  std::string name = instruction.table_.ToString();
  if (!storage.HasMetaData(name)) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  storage.RemoveData(name);

  return new Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<BoolField>(true)} });
}

Table* Driver::Execute(const cmd::Select& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  if (!storage.HasMetaData(instruction.table_.name_)) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString());
  auto& columns_meta = meta.data().at("public");
  std::list<sql::Table::Column> columns;
  for (auto d = columns_meta.items().begin(); d != columns_meta.items().end(); ++d) {
    columns.emplace_back(d.key(), LiteralTypeFromStr(d.value()));
  }

  std::list<sql::Table::Record> records;
  size_t size = meta.data()["private"]["size"];

  if (instruction.type() == cmd::InstructionType::SELECT_ALL) {
    auto data = storage.Read(meta, size);
    for (auto& x : data) {
      sql::Table::Record record;
      for (auto& column : columns) {
        int test = 0;
        switch(column.second) {
          case cmd::LiteralType::INTEGER:
            record.emplace_back(std::make_shared<IntField>(x.Get<int32_t>()));
            break;
          case cmd::LiteralType::DOUBLE:
            record.emplace_back(std::make_shared<DoubleField>(x.Get<double>()));
            break;
          case cmd::LiteralType::BOOL:
            record.emplace_back(std::make_shared<BoolField>(x.Get<bool>()));
            break;
          case cmd::LiteralType::TEXT:
            record.emplace_back(std::make_shared<TextField>(x.Get<std::string>()));
            break;
        }
      }
      records.push_back(record);
    }
  } else if (!instruction.columnDef_.empty()) {
    for (auto& column : instruction.columnDef_) {
      auto result = std::shared_ptr<Table>(column->Accept(*this));
    }
  } else {
    throw std::logic_error("DriverError: Sorry, we don't working with this type of SELECT query yet");
  }
  return new Table(instruction.table_, std::move(columns), std::move(records));
}

Table* Driver::Execute(const cmd::Insert& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  if (!storage.HasMetaData(instruction.table_.name_)) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString());
  if (instruction.into_.empty()) {
    auto &data = meta.data().at("public");
    if (data.size() != instruction.values_.size()) {
      throw std::logic_error("DriverError: The number of values doesn't match the number of columns");
    }
    auto d = data.items().begin();
    se::RawData raw(meta.data()["private"]["size"]);
    for (auto l = instruction.values_.begin(); d != data.items().end() && l != instruction.values_.end(); ++d, ++l) {
      std::string str = data.at(d.key());
      if (LiteralTypeFromStr(str) != l->ValueType()) {
        throw std::logic_error("DriverError: Type of value " + l->Value() + " and type of column " + str + " doesnt't match");
      }
      switch (l->ValueType()) {
        case cmd::LiteralType::INTEGER:
          raw.Fill<int32_t >( std::stoi(l->Value()));
          break;
        case cmd::LiteralType::DOUBLE:
          raw.Fill<double>( std::stod(l->Value()));
          break;
        case cmd::LiteralType::BOOL:
          raw.Fill<bool>( (bool) std::stoi(l->Value()));
          break;
        default:
          raw.Fill<std::string>(l->Value());
      }
    }
    storage.Write(meta, raw.data(), raw.capacity());
  } else {
    throw std::logic_error("DriverError: Sorry, we don't working with this type of INSERT query yet");
  }

  return new Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<BoolField>(true)} });
}

Table* Driver::Execute(const cmd::Update& instruction)
{
  return new Table();
}

Table* Driver::Execute(const cmd::Delete& instruction)
{ 
  return new Table();
}

Table* Driver::Execute(const cmd::ShowCreateTable& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  if (!storage.HasMetaData(instruction.table_.ToString())) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString());

  std::string result =  "CREATE TABLE " + instruction.table_.ToString() + " (";
  for (auto& j : meta.data().at("public").items()) {
    result += j.key() + " " + std::string(j.value()) + ", ";
  }
  result.pop_back();
  result.pop_back();
  result += ");";

  return new Table({ {"result", cmd::LiteralType::TEXT} }, { {std::make_shared<TextField>(result)} });
}

Table* Driver::Execute(const cmd::Literal& instruction)
{
  switch (instruction.ValueType()) {
    case cmd::LiteralType::BOOL:
      return new Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<BoolField>(instruction.bval_)} });

    case cmd::LiteralType::INTEGER:
      return new Table({ {"result", cmd::LiteralType::INTEGER} }, { {std::make_shared<IntField>(instruction.ival_)} });

    case cmd::LiteralType::DOUBLE:
      return new Table({ {"result", cmd::LiteralType::DOUBLE} }, { {std::make_shared<DoubleField>(instruction.fval_)} });

    case cmd::LiteralType::TEXT:
      return new Table({ {"result", cmd::LiteralType::TEXT} }, { {std::make_shared<TextField>(instruction.sval_)} });
  }
  return new Table({ {"result", cmd::LiteralType::NONE} }, { {std::make_shared<Field>()} });
}

Table* Driver::Execute(const cmd::Column& instruction)
{
  auto data = capture.find(instruction.name_);
  if (capture.find(instruction.name_) == capture.end()) {
    return new Table(
        { {instruction.name_, cmd::LiteralType::NONE} },
        { {std::make_shared<Field>()} }
      );
  }
  return new Table({ data->second.first }, { data->second.second });
}

Table* Driver::Execute(const cmd::BinaryOperation& instruction)
{
  auto operandA = std::shared_ptr<Table>(instruction.left_->Accept(*this));
  auto operandB = std::shared_ptr<Table>(instruction.right_->Accept(*this));

  switch (instruction.operation()) {
    // case cmd::OperationType::PLUS:
    //   return Table(operandA + operandB);

    // case cmd::OperationType::MINUS:
    //   return Table(operandA - operandB);

    // case cmd::OperationType::MULTIPLY:
    //   return Table(operandA * operandB);

    // case cmd::OperationType::DIVIDE:
    //   return Table(operandA / operandB);

    // case cmd::OperationType::MOD:
    //   return Table(operandA % operandB);

    // case cmd::OperationType::LESS:
    //   return Table(operandA < operandB);

    // case cmd::OperationType::GREATER:
    //   return Table(operandA > operandB);

    // case cmd::OperationType::EQUAL:
    //   return Table(operandA == operandB);

    // case cmd::OperationType::LESS_EQUAL:
    //   return Table(operandA <= operandB);

    // case cmd::OperationType::GREATER_EQUAL:
    //   return Table(operandA >= operandB);

    // case cmd::OperationType::NOT:
    //   return Table(!operandA);

    // case cmd::OperationType::AND:
    //   return Table(operandA && operandB);

    // case cmd::OperationType::OR:
    //   return Table(operandA || operandB);

    // case cmd::OperationType::XOR:
    //   return Table(operandA ^ operandB);

    // case cmd::OperationType::FUNCTION:
    //   throw std::logic_error("OperationError: Functions is not implemented yet");

    default:
      throw std::logic_error("DriverError: Unknown OperationType");
  }
  return new Table();
}

// TODO: refactor this ...
Table* Driver::Execute(const cmd::UnaryOperation& instruction)
{
  auto operand = std::shared_ptr<Table>(instruction.operator_->Accept(*this));

  switch (instruction.operation()) {
    case cmd::OperationType::UNARY_MINUS:
      return new Table();
    
    case cmd::OperationType::UNARY_PLUS:
      return new Table();
    
    case cmd::OperationType::BIN_NOT:
      return new Table();
    
    case cmd::OperationType::NOT:
      return new Table();
    
    case cmd::OperationType::ISNULL:
      return new Table();

    default:
      throw std::logic_error("DriverError: Unknown OperationType");
  }
  throw std::logic_error("DriverError: Nothing to return from UnaryOperation");
  return new Table();
}

Table* Driver::Execute(const cmd::ColumnDefintion& instruction)
{
  return new Table();
}

} // namespace sql