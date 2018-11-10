#pragma once

#include <string>
#include <list>
#include <unordered_map>
#include <exception>

#include "table.hpp"
#include "parser.hpp"
#include "../parser/sql-stmt/ImportStatements.hpp"


namespace sql {

class Driver {
public:
    static Driver& Instance()
    {
        static Driver instance;
        return instance;
    }

    std::string RunQuery(const std::string) {};

    Table Execute(const cmd::Instruction&);
    Table Execute(const cmd::CreateTable&);
    Table Execute(const cmd::DropTable&);
    Table Execute(const cmd::Select&);
    Table Execute(const cmd::Insert&);
    Table Execute(const cmd::ShowCreateTable&);
private:
    Driver() = default;
};

}