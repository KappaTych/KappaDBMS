#include <exception>

#include "driver.hpp"

namespace sql {

std::string Driver::RunQuery(const std::string query)
{
    auto& parser = Parser::Instance();
    std::list<cmd::Instruction> instructions = parser.Process(query);
    std::list<Table> tables;
    for (auto instruction : instructions) {
        tables.push_back(Execute(instruction.Dispatch()));
    }
}

Table Driver::Execute(const cmd::Instruction& instruction)
{
    auto& instRef = instruction.Dispatch();
    if (instRef.type() == instruction.type()) {
        throw std::exception("DriverError: Invalid instruction");
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
    auto& storage = StorageEngine.Instance();
    if (storage.HasMetaData(instruction.table_.ToString())) {
        throw std::exception("DriverError: Table is already exist");
    }
    se::MetaData& meta = storage.CreateData(instruction.table_.ToString()));
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
    auto& storage = StorageEngine.Instance();
    if (!storage.HasMetaData(instruction.table_.ToString())) {
        throw std::exception("DriverError: Table doesn't exist");
    }
    se::MetaData& meta = storage.GetMetaData(instruction.table_.ToString()));
    Record record({ TextField(instruction.table_.ToString()) });
    cmd::ColumnDefinition column("result", cmd::LiteralType::TEXT);
    return Table({ column }, { record });
}
















// TODO: Think how to do it better
Table Driver::Execute(const cmd::Literal& literal)
{
    return Table( {literal.value()} );
}

Table Driver::Execute(const cmd::Operation& instruction) 
{
    auto& instRef = instruction.Dispatch();
    if (instRef.type() == instruction.type()) {
        throw std::exception("DriverError: Invalid instruction");
    }
    return Execute(instRef);
}

// TODO: refactor this ...
Table Driver::Execute(const cmd::Operation& instruction)
{
    auto& operandA = Execute(instruction.Dispatch());
    auto& operandB = Execute(instruction.Dispatch());

    if (operandA.valueType() != operandB.valueType()) {
        throw std:exception("OperationError: Incompatible ValueType of operands");
    }

    switch (instruction.valueType()) {
        case cmd::OperationType::PLUS:
            return Table(operandA + operandB);

        case cmd::OperationType::MINUS:
            return Table(operandA - operandB);

        case cmd::OperationType::MULTIPLY:
            return Table(operandA * operandB);

        case cmd::OperationType::DIVIDE:
            return Table(operandA / operandB);

        case cmd::OperationType::MOD:
            return Table(operandA % operandB);

        case cmd::OperationType::LESS:
            return Table(operandA < operandB);

        case cmd::OperationType::GREATER:
            return Table(operandA > operandB);

        case cmd::OperationType::EQUAL:
            return Table(operandA == operandB);

        case cmd::OperationType::LESS_EQUAL:
            return Table(operandA <= operandB);

        case cmd::OperationType::GREATER_EQUAL:
            return Table(operandA >= operandB);

        case cmd::OperationType::NOT:
            return Table(!operandA);

        case cmd::OperationType::AND:
            return Table(operandA && operandB);

        case cmd::OperationType::OR:
            return Table(operandA || operandB);

        case cmd::OperationType::XOR:
            return Table(operandA ^ operandB);

        case cmd::OperationType::FUNCTION:
            throw std::exception("OperationError: Functions is not implemented yet");

        default:
            throw std::exception("DriverError: Unknown OperationType");
    }
    throw std::exception("DriverError: Nothing to return from operation");
}

} // namespace sql