#include "MemoryBlock.hpp"

namespace se {

MemoryBlock::MemoryBlock(index_t offset)
  : offset_(offset),
    data_(DEFAULT_CAPACITY) { }

MemoryBlock::MemoryBlock(index_t offset, data_t* data, size_t size)
  : offset_(offset),
    data_(data, size, DEFAULT_CAPACITY) { }

MemoryBlock& MemoryBlock::operator<<(RawData& data)
{
  data_ << data;
  return *this;
}

MemoryBlock& MemoryBlock::operator<<(RawData&& data)
{
  data_ << data;
  return *this;
}

} // namespace se

std::ostream& operator<<(std::ostream& out, const se::MemoryBlock& memoryBlock)
{
  out.seekp( memoryBlock.offset() );
  se::size_t size = memoryBlock.size();
  out.write((const char*) &size, sizeof(se::size_t));
  out << memoryBlock.data();
  return out;
}

std::istream& operator>>(std::istream& in, se::MemoryBlock& memoryBlock)
{
  se::size_t size;
  in.read((char*) &size, sizeof(se::size_t));
  if (size > 0) {
    in >> memoryBlock.data_;
    memoryBlock.data_.size(size);
  } else {
    memoryBlock.data_.FullReset();
  }
  return in;
}