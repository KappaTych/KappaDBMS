//
// Created by nixtaxe on 13.11.18.
//

#include "MetaData.hpp"

se::MetaData::MetaData(std::istream& fin)
{
  // this->read(fin);
}

se::MetaData::MetaData(my_json j) : data_(j) { }

se::MetaData::MetaData(const std::string name) : data_()
{
  data_["private"]["path"] = "database/" + name + ".kp";
}

void se::MetaData::Read(std::istream& fin)
{
  my_json j;
  fin >> j;
  if (j.is_null())
    throw std::invalid_argument("StorageError: Couldn't read metaData-file");
  data_ = j;
}

void se::MetaData::Write(std::ostream& fout)
{
  fout << data_.dump();
}

void se::MetaData::Add(std::string key, int32_t value, std::string group)
{
  data_[group][key] = value;
}

void se::MetaData::Add(std::string key, std::string value, std::string group)
{
  data_[group][key] = value;
}
