#pragma once

#include <memory>
// #include <parser/sql.hpp>


namespace sql {

class Field
{
public:
  Field() = default;
  virtual ~Field() = default;

// TODO: Method for typecasting by some ColumnDefinition& argument

private:
  std::shared_ptr<uint8_t> value_;
  // type_;
};

} // namespace sql