#include "driver.hpp"



namespace sql {

using json = nlohmann::json;

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
    Record record({ TextField(instruction.Value()) });
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
    if (storage.HasMetaData(instruction.table_.ToString())) {
        throw std::logic_error("DriverError: Table is already exist");
    }
    se::MetaData& meta = storage.CreateData(instruction.table_.ToString());
    for (auto& col : instruction.columns_) {
        switch (col.type_) {
            case cmd::LiteralType::BOOL: {
                meta.Add(col.name_, "Boolean");
            }
            case cmd::LiteralType::INTEGER: {
                meta.Add(col.name_, "Integer");                
            }
            case cmd::LiteralType::DOUBLE: {
                meta.Add(col.name_, "Double");
            }
            case cmd::LiteralType::TEXT: {
                meta.Add(col.name_, "Text");
            }
        }
    }
    storage.Flush();

    Record record({ BoolField(true) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::BOOL);
    return new Table({ column }, { record });
}

Table* Driver::Execute(const cmd::DropTable& instruction)
{
    return new Table();
}

Table* Driver::Execute(const cmd::Select& instruction)
{
    return new Table();
}

Table* Driver::Execute(const cmd::Insert& instruction)
{
    return new Table();
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
    for (auto& j : meta.data().items()) {
        if (j.key()[0] == '_') continue;
        result += j.key() + " " + std::string(j.value()) + ", ";
    }
    result.pop_back();
    result.pop_back();
    result += ");";    
    std::cout << result << std::endl;

    Record record({ TextField(result) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
    return new Table({ column }, { record });
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