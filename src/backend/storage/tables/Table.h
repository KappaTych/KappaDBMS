//
// Created by truefinch on 29.10.18.
//
#pragma once

#include <string>
#include <vector>
#include "Record.h"

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



    private:
        std::vector<Column> _columns;
    };
} //namespace tables

