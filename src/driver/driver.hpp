#pragma once

#include <string>
#include <list>
#include <exception>
#include <type_traits>
#include <parser/parser.hpp>
#include <parser/sql.hpp>

#include "datatypes/Table.hpp"


namespace sql {

class Driver {
public:
    static Driver& Instance()
    {
        static Driver instance;
        return instance;
    }

    std::string RunQuery(const std::string);

    Table Execute(const cmd::Instruction&);
    Table Execute(const cmd::Literal&);
    Table Execute(const cmd::Operation&);
    Table Execute(const cmd::CreateTable&);
    Table Execute(const cmd::DropTable&);
    Table Execute(const cmd::Select&);
    Table Execute(const cmd::Insert&);
    Table Execute(const cmd::ShowCreateTable&);

private:
    Driver() = default;
    ~Driver() = default;
    Driver(Driver const &) = delete;
    void operator=(Driver const &) = delete;
};

} // namespace sql