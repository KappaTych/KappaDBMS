#pragma once

#include <cstdlib>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <json.hpp>
#include <fifo_map.hpp>

#include "datatypes/MetaData.hpp"
#include "BlockManager.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{

class StorageEngine
{
public:
  static StorageEngine& Instance()
  {
    static se::StorageEngine instance;
    return instance;
  }

  se::MetaData& CreateData(const std::string& key);

  se::MetaData& GetMetaData(const std::string& key);

  bool HasMetaData(const std::string& key) const;

  void AddRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size);

  bool Flush();

  void operator=(StorageEngine const &) = delete;

private:
  StorageEngine();
  ~StorageEngine() = default;

public:
  se::BlockManager blockManager;

private:
  const std::string META_DATA_PATH = "./database/data.meta";
  std::unordered_map<std::string, MetaData> meta_;

};

} // namespace se