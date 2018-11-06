//
// Created by truefinch on 29.10.18.
//
#pragma once

#include <string>
#include <vector>
#include "Record.h"
#include "../../include/json.hpp"

namespace tables {

    struct Column {
        std::string name;
        dt::DataType dataType;
    };

    class Table {
    public:
        std::string name;
        std::vector<Record> records;

        explicit Table(std::string name, std::vector<Column> columns);

      const std::vector<Column>& getColumns() {return _columns;}

    private:
        std::vector<Column> _columns;
    };
} //namespace tables

namespace tables
{
void to_json(nlohmann::json& j, const Column& r);
void from_json(const nlohmann::json& j, Column& r);
}