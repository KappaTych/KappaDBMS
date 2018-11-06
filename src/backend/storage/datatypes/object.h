//
// Created by truefinch on 02.11.18.
//

#include "../../include/json.hpp"

#pragma once

namespace dt {

    enum DataType {
        INTEGER,
        DOUBLE,
        STRING
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(DataType, {
{DataType::INTEGER, "INTEGER"},
{DataType::DOUBLE, "DOUBLE"},
{DataType::STRING, "TEXT"}
    });

    class object {

    };
} // namespace dt close