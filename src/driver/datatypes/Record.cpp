#include "Record.hpp"

namespace sql {
void to_json(json& j, const Record& r)
{
  //j = json{{"name", t.name_.ToString()}};
}

void from_json(const json& j, Record& r)
{
  //j.at("name").get_to(t.name_.name_);
}
}