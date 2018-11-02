//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <memory>
#include "../datatypes/object.h"

class Field {
public:
    explicit Field(dt::DataType type, std::shared_ptr<dt::object> value = nullptr)
    : _type(type), _value(value) {};
private:
    dt::DataType _type;
    std::shared_ptr<dt::object> _value;
};
