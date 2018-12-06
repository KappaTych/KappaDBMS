#include <exception>

#include "driver.hpp"

namespace sql {

std::string Driver::RunQuery(const std::string query)
{
    auto& parser = Parser::Instance();
    auto instructions = parser.Process(query);
    std::list<Table> tables;
    for (auto& instruction : instructions) {
        tables.push_back(Execute(instruction->Dispatch()));
    }
}

Table Driver::Execute(const cmd::Instruction& instruction)
{
    auto& instRef = instruction.Dispatch();
    if (instRef.type() == instruction.type()) {
        std::string mes = "DriverError: Invalid instruction";
            throw std::logic_error(mes.c_str());
    }
    return Execute(instRef);
}

Table Driver::Execute(const cmd::Literal& instruction)
{
    Record record({ TextField(instruction.Value()) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
    return Table({ column }, { record });
}

Table Driver::Execute(const cmd::TableDefinition& instruction)
{
    return Table(instruction);
}

Table Driver::Execute(const cmd::CreateTable& instruction)
{
    auto& storage = se::StorageEngine::Instance();
    if (storage.HasMetaData(instruction.table_.ToString())) {
        throw std::logic_error("DriverError: Table is already exist");
    }
    se::MetaData& meta = storage.CreateData(instruction.table_.ToString());
    Record record({ BoolField(true) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::BOOL);
    return Table({ column }, { record });
}

Table Driver::Execute(const cmd::DropTable& instruction)
{
    return Table();
}

Table Driver::Execute(const cmd::Select& instruction)
{
    return Table();
}

Table Driver::Execute(const cmd::Insert& instruction)
{
    return Table();
}

Table Driver::Execute(const cmd::Update& instruction)
{
    return Table();
}

Table Driver::Execute(const cmd::Delete& instruction)
{
    return Table();
}

Table Driver::Execute(const cmd::ShowCreateTable& instruction)
{
    auto& storage = se::StorageEngine::Instance();
    if (!storage.HasMetaData(instruction.table_.ToString())) {
        throw std::logic_error("DriverError: Table doesn't exist");
    }
    se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString());
    Record record({ TextField(instruction.table_.ToString()) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
    return Table({ column }, { record });
}

Table Driver::Execute(const cmd::Operation& instruction) 
{
    auto& instRef = instruction.Dispatch();
    if (instRef.type() == instruction.type()) {
        throw std::logic_error("DriverError: Invalid instruction");
    }
    return Execute(instRef);
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