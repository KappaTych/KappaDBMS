//
// Created by truefinch on 02.11.18.
//
#pragma once

#include <vector>

#include "Field.h"

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