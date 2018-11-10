#pragma once

#include <vector>

#include "Field.hpp"

namespace sql
{

class Record
{
public:
  explicit Record(std::vector<Field> fields) : fields_(fields) { }

private:
  std::vector<Field> fields_;
};

} // namespace sql