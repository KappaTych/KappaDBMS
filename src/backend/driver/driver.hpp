#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <exception>
#include "table.hpp"
#include "parser.hpp"
#include "../parser/sql-stmt/instruction.hpp"

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
private:
    Driver() = default;
};

}