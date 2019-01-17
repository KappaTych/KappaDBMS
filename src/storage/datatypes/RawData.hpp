#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <type_traits>
#include <functional>

namespace se {

class RawData;

using data_t = char;
using size_t = uint64_t;
using index_t = uint32_t;
using compare_t = std::function<bool(const RawData&)>;
using filter_t = std::function<bool(RawData&&)>;

} // namespace se

std::ostream& operator<<(std::ostream& out, const se::RawData& raw);
std::istream& operator>>(std::istream& in, se::RawData& raw);

namespace se {

class RawData
{
public:
  static const size_t STRING_LEN = 256;

public:
  bool copied = false;

public:
  friend std::ostream&::operator<<(std::ostream& out, const se::RawData& raw);
  friend std::istream&::operator>>(std::istream& in, se::RawData& raw);

public:
  RawData(size_t capacity);
  RawData(data_t* data, size_t size, size_t capacity, bool copy = true);
  RawData(data_t* data, size_t capacity, bool copy = true);
  virtual ~RawData();

  size_t capacity() const { return capacity_; }
  size_t size() const { return size_; }
  data_t* data() const { return data_; }

  void size(size_t size);

  RawData& operator<<(const RawData& data);

  const RawData& Reset() const
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
  mutable size_t capacity_;
  mutable size_t size_;
  mutable size_t head_;

public:
  template<typename T>
  RawData& Fill(T value, bool relative = false, size_t len = se::RawData::STRING_LEN)
  {
    return Fill(value, relative, len, std::enable_if<true, T>());
  }

  template<typename T>
  T Get(size_t len = se::RawData::STRING_LEN) const
  {
    return Get(len, std::enable_if<true, T>());
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
    if (head_ + count > size_) {
      head_ = size_;
    }
    head_ += count;
    return *this; 
  }

  template<typename T>
  RawData& Fill(T value, bool relative, size_t len, std::enable_if<std::is_arithmetic<T>::value, T>)
  {
    size_t offset = size_;
    if (relative) {
      offset = head_;
    }
    if (offset + sizeof(T) > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    *((T*) (data_ + offset)) = value;
    if (!relative) {
      size_ += sizeof(T);
    }
    return *this;
  }

  RawData& Fill(std::string value, bool relative, size_t len, std::enable_if<true, std::string>)
  {
    size_t offset = size_;
    if (relative) {
      offset = head_;
    }
    if (offset + len > capacity_) {
      throw std::out_of_range("StorageError: RawData Fill-overflowed");
    }
    std::copy(value.c_str(), value.c_str() + value.length() + 1, data_ + offset);
    if (relative) {
      head_ += len;
    } else {
      size_ += len;
    }
    return *this; 
  }

  template<typename T>
  T Get(size_t len, std::enable_if<std::is_arithmetic<T>::value, T>) const
  {
    if (head_ + sizeof(T) > capacity_) {
      throw std::out_of_range("StorageError: RawData Get-overflowed");
    }
    auto offset = head_;
    head_ += sizeof(T);
    return *((T*)(data_ + offset));
  }

  std::string Get(size_t len, std::enable_if<true, std::string>) const
  {
    if (head_ + len > capacity_) {
      throw std::out_of_range("StorageError: RawData Get-overflowed");
    }
    auto offset = head_;
    head_ += len;
    return std::string(data_ + offset); 
  }

};

} //namespace se
