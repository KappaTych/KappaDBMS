#pragma once

#include "Instruction.hpp"
#include "Literal.hpp"


namespace cmd {

class ColumnDefinition : public Instruction 
{
public:
    ColumnDefinition()
            : Instruction(COLUMN_DEF), name_(""), type_(cmd::LiteralType::NONE) {}

    ColumnDefinition(std::string s, cmd::LiteralType t)
            : Instruction(COLUMN_DEF), name_(std::move(s)), type_(t) {}

    sql::Table *Accept(sql::DriverBase &d) override { return d.Execute(*this); }

public: // It's not an error
    std::string name_;
    cmd::LiteralType type_;
};

} // namespace cmd