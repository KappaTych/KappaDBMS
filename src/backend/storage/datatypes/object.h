//
// Created by truefinch on 02.11.18.
//

#pragma once

#include <json.hpp>

namespace sql
{

enum DataType
{
  INTEGER,
  DOUBLE,
  TEXT
};

NLOHMANN_JSON_SERIALIZE_ENUM(DataType, {
  { DataType::INTEGER, "INTEGER" },
  { DataType::DOUBLE,  "DOUBLE" },
  { DataType::TEXT,    "TEXT" }
});

class object {};

} // namespace sql