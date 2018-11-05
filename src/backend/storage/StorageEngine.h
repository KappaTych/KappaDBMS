//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <vector>
#include <map>
#include <string>
#include "tables/Table.h"

namespace se {
    class StorageEngine {
    public:
        bool create(std::string name, std::vector<tables::Column> columns);
        tables::Table show_create();
    private:
        std::map<std::string, tables::Table> _tables;
    };
} // namespace se


