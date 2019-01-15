#pragma once

#include <memory>
#include <string>

namespace se {

class RawData;

using data_t = char;
using size_t = uint64_t;
using index_t = uint32_t;
using compare_t = bool (*)(RawData&&);


class RawData
{
public:
  static const size_t STRING_LEN = 256;

public:
  bool copied = false;

public:
  RawData(size_t capacity) : data_(new data_t[capacity]), head_(0), size_(0), capacity_(capacity) { };
  RawData(data_t* data, size_t capacity, bool copy = true) : head_(0), size_(capacity), capacity_(capacity)
  {
    if (copied = copy) {
      data_ = new data_t[size], 
      std::copy(data, data + size, data_);
    } else {
      data_ = data;
    }
  };
  ~RawData() { if (copied) delete[] data_; }

  size_t capacity() const { return capacity_; }
  const data_t* data() const { return data_; }

  RawData& Reset()
  {
    head_ = 0;
    return *this;
  }

  RawData& FullReset()
  {
    head_ = 0;
    size_ = 0;
    return *this;
  }

private:
  data_t* data_;
  size_t capacity_;
  size_t size_;
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

  template<typename T>
  RawData& Skip(size_t count = 1)
  {
    return Skip(count, std::enable_if<true, T>());
  }

private:
  template<typename T>
  RawData& Skip(size_t count, std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    if (head_ + sizeof(T) * count > size_) {
      head_ = size_;
    }
    head_ += sizeof(T) * count;
    return *this;
  }

  RawData& Skip(size_t count, std::enable_if<true, std::string>)
  {
    if (head_ + STRING_LEN * count > size_) {
      head_ = size_;
    }
    head_ += STRING_LEN * count;
    return *this; 
  }

  template<typename T>
  RawData& Fill(T value, std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    if (size_ + sizeof(T) > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    *((T*) (data_ + size_)) = value;
    size_ += sizeof(T);
    return *this;
  }

  RawData& Fill(std::string value, std::enable_if<true, std::string>)
  {
    if (size_ + STRING_LEN > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    std::copy(value.c_str(), value.c_str() + value.length() + 1, data_ + size_);
    size_ += STRING_LEN;
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
