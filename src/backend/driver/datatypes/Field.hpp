#pragma once

#include <memory>
// #include <parser/sql.hpp>


namespace sql {

class Field
{
public:
  Field() = default;
  virtual ~Field() = default;
};

class DoubleField : public Field
{
public:
  DoubleField(double value) : value_(value) {}
  double GetValue() { return value_ }
  void SetValue(double value) { value_ = value }
private:
  double value_;
}

class BoolField : public Field
{
public:
  BoolField(bool value) : value_(value) {}
  bool GetValue() { return value_ }
  void SetValue(bool value) { value_ = value }
private:
  bool value_;
}

class TextField : public Field
{
public:
  TextField(std::string value) : value_(value) {}
  std:string GetValue() { return value_ }
  void SetValue(std::string value) { value_ = value }
private:
  std::string value_;
}

} // namespace sql