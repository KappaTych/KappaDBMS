//
// Created by nixtaxe on 10.11.18.
//

#pragma once

#include <json.hpp>
#include <fifo_map.hpp>

template<class K, class V, class dummy_compare, class A> using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{

class MetaData
{
public:
  MetaData() = delete;
  MetaData(std::istream& fin);
  MetaData(const std::string name);
  MetaData(my_json j);

public:
  void Read(std::istream& fin);
  void Write(std::ostream& fout);

  void Add(std::string key, int32_t value, std::string group = "public");
  void Add(std::string key, std::string value, std::string group = "public");
  // TODO: operator[]

public:
  my_json& data() { return data_; }
  std::string getName() { return data_["private"]["path"]; }

private:
  my_json data_;
};

} //namespace se