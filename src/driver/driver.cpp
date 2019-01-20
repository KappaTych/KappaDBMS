#include "driver.hpp"

namespace sql {

using json = nlohmann::json;

cmd::LiteralType LiteralTypeFromStr(const std::string str) {
    if (str == "INTEGER")
        return cmd::LiteralType::INTEGER;
    else if (str == "DOUBLE")
        return cmd::LiteralType::DOUBLE;
    else if (str == "TEXT")
        return cmd::LiteralType::TEXT;
    else if (str == "BOOL")
        return cmd::LiteralType::BOOL;
    else
        return cmd::LiteralType::NONE;
}

std::string Driver::RunQuery(const std::string query)
{
  auto& parser = Parser::Instance();
  auto instructions = parser.Process(query);
  std::vector<Table> tables;
  for (auto& instruction : instructions) {
    Table* t = instruction->Accept(*this);
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
  throw std::logic_error("DriverError: Invalid instruction. Didn't find child instruction");
}

Table* Driver::Execute(const cmd::Literal& instruction)
{
  Record record({ std::make_shared<TextField>(TextField(instruction.Value())) });
  cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
  return new Table({ column }, { record });
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

  Record record({ std::make_shared<BoolField>(BoolField(true)) });
  cmd::ColumnDefinition column("result", cmd::LiteralType::BOOL);
  cmd::TableDefinition definition("anonymous");
  return new Table({definition}, { column }, { record });
}

Table* Driver::Execute(const cmd::DropTable& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  std::string name = instruction.table_.ToString();
  if (!storage.HasMetaData(name)) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  storage.RemoveData(name);

  Record record({ std::make_shared<BoolField>(BoolField(true)) });
  cmd::ColumnDefinition column("result", cmd::LiteralType::BOOL);
  cmd::TableDefinition definition("anonymous");
  return new Table({definition}, { column }, { record });
}

Table* Driver::Execute(const cmd::Select& instruction)
{
  auto& storage = se::StorageEngine::Instance();
  if (!storage.HasMetaData(instruction.table_.name_)) {
    throw std::logic_error("DriverError: Table doesn't exist");
  }
  se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString());
  auto& columns_meta = meta.data().at("public");
  std::list<cmd::ColumnDefinition> columns_def;
  for (auto d = columns_meta.items().begin(); d != columns_meta.items().end(); ++d) {
    columns_def.emplace_back(d.key(), LiteralTypeFromStr(d.value()));
  }

  std::list<Record> records;
  if (instruction.type() == cmd::InstructionType::SELECT_ALL) {
    size_t size = meta.data()["private"]["size"];
    auto dataAll = storage.Read(meta, size);
    for (auto& x : dataAll) {
      std::list<FieldSPtr> fields;
      for (auto& column : columns_def) {
        switch(column.type_) {
          case cmd::LiteralType::INTEGER:
            fields.emplace_back(std::make_shared<IntField>(x.Get<int32_t>()));
            break;
          case cmd::LiteralType::DOUBLE:
            fields.emplace_back(std::make_shared<DoubleField>(x.Get<double>()));
            break;
          case cmd::LiteralType::BOOL:
            fields.emplace_back(std::make_shared<BoolField>(x.Get<bool>()));
            break;
          case cmd::LiteralType::TEXT:
            fields.emplace_back(std::make_shared<TextField>(x.Get<std::string>()));
            break;
        }
      }
      records.push_back(Record(fields));
    }
    return new Table(instruction.table_, std::move(columns_def), std::move(records));
  }
  return  new Table();
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
        case cmd::LiteralType::TEXT:
          raw.Fill<std::string>( l->Value());
          break;
      }
    }
    storage.Write(meta, raw.data(), raw.capacity());
  }
  else {
    throw std::logic_error("DriverError: Sorry, we don't working with this type of SELECT query yet");
  }

  Record record({ std::make_shared<BoolField>(BoolField(true)) });
  cmd::ColumnDefinition column("result", cmd::LiteralType::BOOL);
  cmd::TableDefinition definition("anonymous");

  return new Table({definition}, { column }, { record });
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

  Record record({ std::make_shared<TextField>(TextField(result)) });
  cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
  cmd::TableDefinition definition("anonymous");
  return new Table({definition}, { column }, { record });
}

Table* Driver::Execute(const cmd::Operation& instruction)
{
  return new Table();
}

Table* Driver::Execute(const cmd::Column&)
{
  return new Table();
}

Table* Driver::Execute(const cmd::ColumnDefintion&)
{
  return new Table();
}

Table* Driver::Execute(const cmd::Expression &)
{
  return new Table();
}

// TODO: refactor this ...
// Table Driver::Execute(const cmd::Operation& instruction)
// {
//     // auto& operandA = Execute(instruction.Dispatch());
//     // auto& operandB = Execute(instruction.Dispatch());

//     // if (operandA.ValueType() != operandB.ValueType()) {
//     //     throw std::logic_error("OperationError: Incompatible ValueType of operands");
//     // }

//     // switch (instruction.ValueType()) {
//     //     case cmd::OperationType::PLUS:
//     //         return Table(operandA + operandB);

//     //     case cmd::OperationType::MINUS:
//     //         return Table(operandA - operandB);

//     //     case cmd::OperationType::MULTIPLY:
//     //         return Table(operandA * operandB);

//     //     case cmd::OperationType::DIVIDE:
//     //         return Table(operandA / operandB);

//     //     case cmd::OperationType::MOD:
//     //         return Table(operandA % operandB);

//     //     case cmd::OperationType::LESS:
//     //         return Table(operandA < operandB);

//     //     case cmd::OperationType::GREATER:
//     //         return Table(operandA > operandB);

//     //     case cmd::OperationType::EQUAL:
//     //         return Table(operandA == operandB);

//     //     case cmd::OperationType::LESS_EQUAL:
//     //         return Table(operandA <= operandB);

//     //     case cmd::OperationType::GREATER_EQUAL:
//     //         return Table(operandA >= operandB);

//     //     case cmd::OperationType::NOT:
//     //         return Table(!operandA);

//     //     case cmd::OperationType::AND:
//     //         return Table(operandA && operandB);

//     //     case cmd::OperationType::OR:
//     //         return Table(operandA || operandB);

//     //     case cmd::OperationType::XOR:
//     //         return Table(operandA ^ operandB);

//     //     case cmd::OperationType::FUNCTION:
//     //         throw std::exception("OperationError: Functions is not implemented yet");

//     //     default:
//     //         throw std::exception("DriverError: Unknown OperationType");
//     // }
//     // throw std::exception("DriverError: Nothing to return from operation");
//     return Table();
// }

} // namespace sql