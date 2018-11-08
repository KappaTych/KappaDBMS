//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, std::vector<tables::Column> columns)
:name(std::move(name)), _columns(std::move(columns)){
}