#include "RawData.hpp"


namespace se {

RawData::~RawData() { if (copied) delete[] data_; }

RawData::RawData(size_t capacity)
  : data_(new data_t[capacity]),
    head_(0),
    size_(0),
    capacity_(capacity) { }

RawData::RawData(data_t* data, size_t size, size_t capacity, bool copy)
  : head_(0),
    size_(size), capacity_(capacity)
{
  if (copied = copy) {
    data_ = new data_t[capacity], 
    std::copy(data, data + size_, data_);
  } else {
    data_ = data;
  }
}

RawData::RawData(data_t* data, size_t capacity, bool copy)
  : head_(0),
    size_(capacity),
    capacity_(capacity)
{
  if (copied = copy) {
    data_ = new data_t[capacity], 
    std::copy(data, data + capacity, data_);
  } else {
    data_ = data;
  }
}

void RawData::size(size_t size)
{
  if (size > capacity_) {
    throw std::out_of_range("StorageError: RawData size-overflowed");
  }
  size_ = size;
}

RawData& RawData::operator<<(const RawData& data)
{
  if (size_ + data.size() > capacity_) {
    throw std::out_of_range("StorageError: RawData overflowed");
  }
  std::copy(data.data_, data.data_ + data.size_, data_ + size_);
  size_ += data.size();
  return *this;
}

} // namespace se


std::ostream& operator<<(std::ostream& out, const se::RawData& raw)
{
  out.write(raw.data_, raw.capacity());
  out.flush();
  return out;
}

std::istream& operator>>(std::istream& in, se::RawData& raw)
{
  in.read(raw.data_, raw.capacity_);
  raw.size_ = raw.capacity_;
  return in;
}