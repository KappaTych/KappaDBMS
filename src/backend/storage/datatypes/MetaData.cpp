//
// Created by nixtaxe on 13.11.18.
//

#include "MetaData.h"

se::MetaData::MetaData(std::ifstream& fin)
{
  this->read(fin);
}

se::MetaData::MetaData(my_json j)
{
  data() = std::make_shared<my_json>(j);
}

void se::MetaData::read(std::ifstream& fin)
{
  my_json j;
  fin >> j;
  if (j.is_null())
    throw std::invalid_argument("No such file or directory");
  data_ = std::make_shared<my_json>(j);
}

void se::MetaData::write(std::ofstream& fout)
{
  fout << data_.get()->dump();
}

void se::MetaData::add(std::string key, size_t size)
{
  data_.get()->push_back({key, size});
}

void se::MetaData::add(std::string key, std::string str)
{
  data_.get()->push_back({key, str});
}

se::MetaData::MetaData(std::string name) : data_(my_json())
{
  data_.get()->("name", name);
}
