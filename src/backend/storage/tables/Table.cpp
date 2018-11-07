//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, std::vector<std::pair<std::string, dt::DataType>> columns) : name(
    std::move(name)), _columns(columns.begin(), columns.end())
{
}