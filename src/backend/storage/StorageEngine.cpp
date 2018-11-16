#include "StorageEngine.hpp"

se::StorageEngine::StorageEngine() : blockManager(), meta_()
{
  std::ifstream fin(META_DATA_PATH);
  if (!fin.is_open()) {
    throw std::invalid_argument("StorageError: Couldn't open metaData-file.");
  }
  my_json j;
  fin >> j;
  if (!j.empty()) {
    for (auto it = j.begin(); it != j.end(); ++it) {
      meta_.at(it.key()) = it.value();
    }
  }
}

bool se::StorageEngine::Flush()
{
  // my_json j;
  // std::ofstream fout;

  // for (auto& table : tables_) {
  //   j[table.first] = table.second.getColumns();
  //   fout.open("./database/" + table.first + ".kp", std::ios_base::binary);
  //   for (auto record : table.second.records)
  //     if (record.get() != NULL) {
  //       fout.write(record.get(), sizeof(record.get()));
  //     }
  //   fout.close();
  // }

  // std::string result = j.dump();
  // fout.open(se::StorageEngine::META_DATA_PATH);
  // if (!fout.is_open()) {
  //   return false;
  // }
  // fout << result;
  // fout.close();

  return true;
}

se::MetaData& se::StorageEngine::CreateData(const std::string& key)
{
  if (meta_.find(key) == meta_.end()) {
    throw std::invalid_argument("StorageError: Data already exists");
  }
  auto md = se::MetaData(key);
  blockManager.CreateBlockList(md);
  meta_.insert({key, md});
}

se::MetaData& se::StorageEngine::GetMetaData(const std::string& key)
{
  // std::ifstream fin;
  // fin.open(se::StorageEngine::META_DATA_PATH);
  // if (!fin.is_open()) {
  //   throw std::invalid_argument("No such file or directory.");
  // }

  // se::MetaData j;
  // j.read(fin);
  // fin.close();
  // if (j.data()->find(key) == j.data()->end())
  //   throw std::range_error("No such table");

  // return se::MetaData(j.data()->at(key));
  return meta_.at(key);
}

void se::StorageEngine::AddRow(se::MetaData& metaData, std::shared_ptr<uint8_t>& row, size_t size)
{
  blockManager.AddRow(metaData, row, size);
}
