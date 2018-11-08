//
// Created by truefinch on 02.11.18.
//

#pragma once

#include "../../include/json.hpp"

namespace dt
{

enum DataType
{
  INTEGER, DOUBLE, TEXT
};

NLOHMANN_JSON_SERIALIZE_ENUM(DataType, {
  { DataType::INTEGER, "INTEGER" }, { DataType::DOUBLE, "DOUBLE" }, { DataType::TEXT, "TEXT" }
});

class object
{

};
} // namespace dt close