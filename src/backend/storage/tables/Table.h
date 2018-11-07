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

        explicit Table(std::string name, std::vector<std::pair<std::string, dt::DataType>> columns);

      const std::map<std::string, dt::DataType>& getColumns() {return _columns;}

    private:
        std::map<std::string, dt::DataType> _columns;
    };
} //namespace tables