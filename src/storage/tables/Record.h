//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <vector>

#include "Field.h"

class Record {
public:
    std::vector<Field> _fields;

    explicit Record(std::vector<Field> fields) : _fields(fields) {};
};
