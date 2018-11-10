#pragma once

#include <memory>
// #include <parser/sql.hpp>


namespace sql {

class Field
{
public:
  Field() = default;
  virtual ~Field() = default;

private:
  std::shared_ptr<uint8_t> value_;
  // type_;
}

} // namespace sql