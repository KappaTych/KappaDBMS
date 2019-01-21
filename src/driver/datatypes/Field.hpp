#pragma once

#include <memory>
#include <json.hpp>
#include <string>

namespace sql
{

using json = nlohmann::json;

class Field
{
public:
  Field() = default;
  virtual ~Field() = default;
  virtual void Value(void* value) const { *((char*) value) = 0; };
  virtual std::string ToString() const { return "null"; }
};

class DoubleField : public Field
{
public:
  DoubleField(double value) : value_(value) {}
  double GetValue() { return value_; }
  void SetValue(double value) { value_ = value; }
  void Value(void* value) { *((double*) value) = value_; }
  std::string ToString() const { return std::to_string(value_); }
private:
  double value_;
};

class BoolField : public Field
{
public:
  BoolField(bool value) : value_(value) {}
  bool GetValue() { return value_; }
  void SetValue(bool value) { value_ = value; }
  void Value(void* value) { *((bool*) value) = value_; }
  std::string ToString() const { return value_ ? "true" : "false"; }
private:
  bool value_;
};

class TextField : public Field
{
public:
  TextField(std::string value) : value_(value) {}
  std::string GetValue() { return value_; }
  void SetValue(std::string value) { value_ = value; }
  void Value(void* value) { *((std::string*) value) = value_; }
  std::string ToString() const { return value_; }
private:
  std::string value_;
};

class IntField : public Field
{
public:
  IntField(int32_t value) : value_(value) {}
  int32_t GetValue() { return value_; }
  void SetValue(int32_t value) { value_ = value; }
  void Value(void* value) { *((int32_t*) value) = value_; }
  std::string ToString() const { return std::to_string(value_); }
private:
  int32_t value_;
};

} // namespace sql