//
// Created by nixtaxe on 13.11.18.
//

#include "MetaData.hpp"

se::MetaData::MetaData(std::istream& fin)
{
  // this->read(fin);
}

se::MetaData::MetaData(my_json j) : data_(std::make_shared<my_json>(j)) { }

se::MetaData::MetaData(const std::string name) : data_(std::make_shared<my_json>())
{
  (*data_)["_path"] = "database/" + name + ".kp";
  (*data_)["_size"] = 0;
}

void se::MetaData::Read(std::istream& fin)
{
  my_json j;
  fin >> j;
  if (j.is_null())
    throw std::invalid_argument("StorageError: Couldn't read metaData-file");
  data_ = std::make_shared<my_json>(j);
}

void se::MetaData::Write(std::ostream& fout)
{
  fout << data_.get()->dump();
}

void se::MetaData::Add(std::string key, size_t size)
{
  data_.get()->push_back({key, size});
}

void se::MetaData::Add(std::string key, std::string value)
{
  data_.get()->push_back({key, value});
}
