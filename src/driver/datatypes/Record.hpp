#pragma once

#include <list>
#include <memory>
#include <json.hpp>
#include "Field.hpp"


namespace sql {

using json = nlohmann::json;

class Record
{
public:
  explicit Record(std::list<Field> fields) : fields_(fields) {}
    std::list<Field> GetFields() const {  return fields_; }
// TODO: Method AddField / AddValue / AddColumn <-- one of them
// TODO: Method for getting i-th Field
private:
  std::list<Field> fields_;
};

  void to_json(json& j, const Record& r);
  void from_json(const json& j, Record& r);

} // namespace sql