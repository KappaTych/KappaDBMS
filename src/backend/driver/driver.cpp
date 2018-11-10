#include "driver.hpp"

namespace sql {

std::string Driver::RunQuery(const std::string query)
{
    auto& parser = Parser::Instance();
    std::list<cmd::Instruction> instructions = parser.Process(query);
    std::list<Table> tabels;
    for (auto instruction : instructions) {
        tabels.push_back(Execute(instruction.Dispatch()));
    }
}

Table Driver::Execute(const cmd::Instruction& instruction)
{
    throw (std::exception("invalid instruction"));
}

Table Driver::Execute(const cmd::CreateTable& instruction)
{
    return Table();
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

Table Driver::Execute(const cmd::ShowCreateTable& instruction)
{
    return Table();
}

}