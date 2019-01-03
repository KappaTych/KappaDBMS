#pragma once

#include <vector>
#include <json.hpp>
#include "Field.hpp"


namespace sql {

using json = nlohmann::json;

class Record
{
public:
  explicit Record(std::vector<Field> fields) : fields_(fields) { }
// TODO: Method AddField / AddValue / AddColumn <-- one of them
// TODO: Method for getting i-th Field

private:
  std::vector<Field> fields_;
};

  void to_json(json& j, const Record& t);
  void from_json(const json& j, Record& t);

} // namespace sql