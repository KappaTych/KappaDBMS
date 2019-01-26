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
#include <cppfs/FilePath.h>
#include <mutex>
// #include <btree/btree_map.h>

#include "datatypes/MemoryBlock.hpp"
#include "datatypes/BlockList.hpp"
#include "datatypes/MetaData.hpp"
#include "datatypes/RawData.hpp"

template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

namespace se
{

using compare_t = std::function<bool(const RawData&)>;
using update_t = std::function<bool(RawData&&)>;

static std::string ROOT;

class StorageEngine
{
public:
  static StorageEngine& Instance()
  {
    static se::StorageEngine instance;
    return instance;
  }
  void operator=(StorageEngine const &) = delete;

  static void SetRootPath(const std::string& path);

  static const std::string& GetRootPath();

  MetaData& CreateData(uint64_t id, const std::string& key);
  void RemoveData(uint64_t id, const std::string& key);
  MetaData& GetMetaData(uint64_t id, const std::string& key);
  bool HasMetaData(uint64_t id, const std::string& key) const;
  void UpdateMetaData(uint64_t id, const std::string& key);

  // for transaction
  uint64_t StartTransaction();
  void Commit(uint64_t id);
  void RollBack(uint64_t id);

//  void CreateIndex(std::string tableName, uint32_t columnIndex);

  std::list<RawData> Read(uint64_t id, MetaData& metaData, size_t size, const compare_t& func = [](const RawData& x){ return true; });
  void Write(uint64_t id, MetaData& metaData, const char* row, size_t size);
  void Update(uint64_t id, MetaData& metaData, size_t size, const update_t& func = [](RawData&& x){ return true; });
  void Delete(uint64_t id, MetaData& metaData, size_t size, const compare_t& func);

private:
  StorageEngine();
  ~StorageEngine() = default;

  void checkKey(const std::string& key);
  BlockList& LoadBlockList(MetaData& metaData);
  bool FlushMeta();

  std::list<RawData> Read(BlockList& block, size_t size, const compare_t& func);
  void Write(BlockList& block, const char* row, size_t size);
  void Update(BlockList& block, size_t size, const update_t& func);
  void Delete(BlockList& block, size_t size, const compare_t& func);


  const std::string META_DATA_PATH = "database/data.meta";
  // committed data
  std::unordered_map<std::string, MetaData> meta_;
  std::unordered_map<std::string, std::shared_ptr<BlockList>> data_;
  // std::map< std::string, btree::btree_map<uint32_t, se::RawData> > indexes_;
  std::mutex m_writer;

  std::unordered_map<uint64_t, std::unordered_map<std::string, MetaData>> uncommittedMeta_;
  std::unordered_map<uint64_t, std::unordered_map<std::string, std::shared_ptr<BlockList>>> uncommittedData_;
  std::unordered_map<uint64_t, std::unordered_map<std::string, std::shared_ptr<BlockList>>> uncommittedDropTable_;

  BlockList& getUncommittedBlockList(uint64_t id, MetaData& metaData);
};

} // namespace se