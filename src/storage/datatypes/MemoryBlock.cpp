#include "MemoryBlock.hpp"

namespace se {

MemoryBlock::MemoryBlock(index_t offset)
  : offset_(offset),
    data_(std::make_shared<DataBlock>(new data_t[DEFAULT_CAPACITY], 0)) { }

MemoryBlock::MemoryBlock(index_t offset, data_t* data, size_t size)
  : offset_(offset),
    data_(std::make_shared<DataBlock>(new data_t[DEFAULT_CAPACITY], size))
{
  std::copy(data, data + size, data_->data);
}

MemoryBlock& MemoryBlock::operator<<(DataBlock&& data)
{
  if (data_->size + data.size > capacity_) {
    throw std::range_error("StorageError: DataBlock overflow");
  }
  std::copy(data.data, data.data + data.size, data_->data + data_->size);
  data_->size += data.size;
  return *this;
}

} // namespace se

std::fstream& operator<<(std::fstream& fout, const se::MemoryBlock& memoryBlock)
{
  fout.seekp( memoryBlock.offset() );
  se::size_t size = memoryBlock.size();
  fout.write((const char*) &size, sizeof(se::size_t));
  fout.write(memoryBlock.data()->data, memoryBlock.capacity());
  fout.flush();
  return fout;
}

std::istream& operator>>(std::istream& fin, se::MemoryBlock& memoryBlock)
{
  se::size_t size;
  fin.read((char*) &size, sizeof(se::size_t));
  memoryBlock.size(size);
  if (size > 0) {
    fin.read(memoryBlock.data()->data, memoryBlock.capacity());
  }
  return fin;
}