#pragma once

#include <vector>

#include "Field.hpp"

namespace sql {

class Record
{
public:
  explicit Record(std::vector<Field> fields) : fields_(fields) { }

// TODO: Method AddField / AddValue / AddColumn <-- one of them
// TODO: Method for getting i-th Field

private:
  std::vector<Field> fields_;
};

} // namespace sql