#include "Field.hpp"

namespace sql {

void to_json(json& j, const Field& t)
{
  j = json{{"name", ""}};
}

void from_json(const json& j, Field& t)
{
  
}

}