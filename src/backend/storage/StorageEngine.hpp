#pragma once

#include <cstdlib>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <json.hpp>
#include <fifo_map.hpp>

#include "tables/Table.hpp"
#include "datatypes/object.hpp"
#include "BlockManager.hpp"
#include "datatypes/MetaData.hpp"

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

  bool HasMetaData(const std::string& metaData) const;

  se::MetaData& GetMetaData(const std::string& metaData);

  se::MetaData& CreateData(se::MetaData&);

  void AddRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size);

  bool Flush();


  void operator=(StorageEngine const &) = delete;

public:
  se::BlockManager blockManager;

private:
  std::map<std::string, sql::Table> tables_;

  StorageEngine() = default;
  ~StorageEngine() = default;

private:
  const std::string META_DATA_PATH = "../database/tables.json";
  std::map<std::string, sql::Table> tables_;
};

} // namespace se