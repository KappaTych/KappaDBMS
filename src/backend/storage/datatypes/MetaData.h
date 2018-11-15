//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <json.hpp>
#include <fifo_map.hpp>
#include "MemoryBlock.h"

template<class K, class V, class dummy_compare, class A> using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{

class MetaData
{
public:
  MetaData() = default;

  MetaData(std::ifstream& fin);

public:
  void read(std::ifstream& fin);

  void write(std::ofstream& fout);

public:
  std::shared_ptr<my_json> data()
  { return data_; }

private:
  std::shared_ptr<my_json> data_;
};

} //namespace se