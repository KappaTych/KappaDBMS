//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <memory>
#include "../datatypes/object.h"

namespace sql
{

class Field {
public:
  explicit Field(DataType type, std::shared_ptr<object> value = nullptr) : type_(type), value_(value) { }

private:
  DataType type_;
  std::shared_ptr<object> value_;
};

} // namespace sql