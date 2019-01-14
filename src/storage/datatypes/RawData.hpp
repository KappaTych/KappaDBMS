#pragma once

#include <memory>
#include <string>

namespace se {

using size_t = uint32_t;
using data_t = char;
using index_t = uint32_t;

// TODO: overflow errors checking

class RawData
{
public:
  RawData(size_t size) : data_(new data_t[size]), len_(0), capacity_(size) { };

  size_t capacity() const { return capacity_; }
  const data_t* data() const { return data_; }

private:
  data_t* data_;
  size_t capacity_;
  size_t len_;

public:
  template<typename T>
  RawData& Fill(T value)
  {
    return Fill(value, std::enable_if<true, T>());
  }

private:
  template<typename T>
  RawData& Fill(T value, std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    *((T*) (data_ + len_)) = value;
    len_ += sizeof(value);
    return *this;
  }

  RawData& Fill(std::string value, std::enable_if<true, std::string>)
  {
    std::copy(value.c_str(), value.c_str() + value.length(), data_ + len_);
    len_ += value.length();
    data_[len_++] = 0;
    return *this; 
  }

};

} //namespace se
