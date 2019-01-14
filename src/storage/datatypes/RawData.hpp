#pragma once

#include <memory>
#include <string>

namespace se {

using data_t = char;
using size_t = uint64_t;
using index_t = uint32_t;
using compare_t = bool (*)(data_t*, size_t);


class RawData
{
public:
  static const size_t STRING_LEN = 256;

public:
  RawData(size_t size) : data_(new data_t[size]), head_(0), len_(0), capacity_(size) { };
  RawData(data_t* data, size_t size) : data_(new data_t[size]), head_(0), len_(size), capacity_(size)
  {
    std::copy(data, data + size, data_);
  };
  ~RawData() { delete[] data_; }

  size_t capacity() const { return capacity_; }
  const data_t* data() const { return data_; }

  void Reset()
  {
    len_ = 0;
    head_ = 0;
  }

private:
  data_t* data_;
  size_t capacity_;
  size_t len_;
  size_t head_;

public:
  template<typename T>
  RawData& Fill(T value)
  {
    return Fill(value, std::enable_if<true, T>());
  }

  template<typename T>
  T Get()
  {
    return Get(std::enable_if<true, T>());
  }

private:
  template<typename T>
  RawData& Fill(T value, std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    if (len_ + sizeof(T) > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    *((T*) (data_ + len_)) = value;
    len_ += sizeof(T);
    return *this;
  }

  RawData& Fill(std::string value, std::enable_if<true, std::string>)
  {
    if (len_ + STRING_LEN > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    std::copy(value.c_str(), value.c_str() + value.length() + 1, data_ + len_);
    len_ += STRING_LEN;
    return *this; 
  }

  template<typename T>
  T Get(std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    if (head_ + sizeof(T) > capacity_) {
      throw std::out_of_range("StorageError: RawData Get-overflowed");
    }
    auto offset = head_;
    head_ += sizeof(T);
    return *((T*)(data_ + offset));
  }

  std::string Get(std::enable_if<true, std::string>)
  {
    if (head_ + STRING_LEN > capacity_) {
      throw std::out_of_range("StorageError: RawData Get-overflowed");
    }
    auto offset = head_;
    head_ += STRING_LEN;
    return std::string(data_ + offset); 
  }

};

} //namespace se
