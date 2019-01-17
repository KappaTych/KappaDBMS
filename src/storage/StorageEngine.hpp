#pragma once

#include <cstdlib>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <unordered_map>
#include <json.hpp>
#include <fifo_map.hpp>
#include <cppfs/fs.h>
#include <cppfs/FileHandle.h>
// #include <btree/btree_map.h>

#include "datatypes/MemoryBlock.hpp"
#include "datatypes/BlockList.hpp"
#include "datatypes/MetaData.hpp"
#include "datatypes/RawData.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se {

static std::string ROOT;

class StorageEngine
{
public:
  static StorageEngine& Instance()
  {
    static se::StorageEngine instance;
    return instance;
  }

  static void SetRootPath(const std::string& path);

  static const std::string& GetRootPath();

  MetaData& CreateData(const std::string& key);
//  void CreateIndex(std::string tableName, uint32_t columnIndex);

  MetaData& GetMetaData(const std::string& key);

  bool HasMetaData(const std::string& key) const;

  BlockList& LoadBlockList(MetaData& metaData);

  void Write(MetaData& metaData, const char* row, size_t size);
  void Filter(MetaData& metaData, size_t size, const filter_t& func);
  std::list<RawData> Read(MetaData& metaData, size_t size, const compare_t& cmp = [](const RawData& x){ return true; });

  bool Flush();

  void operator=(StorageEngine const &) = delete;

private:
  StorageEngine();
  ~StorageEngine() = default;

  const std::string META_DATA_PATH = "database/data.meta";
  std::unordered_map<std::string, MetaData> meta_;
  std::unordered_map<std::string, std::shared_ptr<BlockList>> data_;
  // std::map< std::string, btree::btree_map<uint32_t, se::RawData> > indexes_;
};

} // namespace se