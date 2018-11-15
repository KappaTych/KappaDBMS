//
// Created by nixtaxe on 13.11.18.
//

#include "MetaData.h"

se::MetaData::MetaData(std::ifstream& fin)
{
  this->read(fin);
}

void se::MetaData::read(std::ifstream& fin)
{
  my_json j;
  fin >> j;
  if (j.is_null())
    return;
  data_ = std::make_shared<my_json>(j);
}

void se::MetaData::write(std::ofstream& fout)
{
  fout << data_.get()->dump();
}
