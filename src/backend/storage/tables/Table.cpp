//
// Created by truefinch on 29.10.18.
//
#include <utility>

#include "Table.h"

tables::Table::Table(std::string name, std::vector<tables::Column> columns)
:name(std::move(name)), _columns(std::move(columns)){
}

namespace tables
{

void to_json(nlohmann::json& j, const Column& r)
{
  j = nlohmann::json{
      {"name", r.name},
      {"dataType", r.dataType}
  };
}

void from_json(const nlohmann::json& j, Column& r)
{
  r.name = j.at( "name" ).get <std::string>();
  r.dataType = j.at("dataType").get<dt::DataType>();
}

}
