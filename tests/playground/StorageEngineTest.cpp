#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdint>
#include <btree/safe_btree_map.h>
#include <cppfs/FilePath.h>

#include <unordered_map>
#include <string>

#include <storage/StorageEngine.hpp>
#include <storage/datatypes/RawData.hpp>


int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );
  auto& storage = se::StorageEngine::Instance();

  std::unordered_map<std::string, int> mapping = {
    {"INTEGER", sizeof(int32_t)},
    {"TEXT", 256},
  };

  if (!storage.HasMetaData("some_table")) {
    auto meta = storage.CreateData("some_table");
    meta.Add("id", "INTEGER");
    meta.Add("name", "TEXT");
    meta.Add("count", "INTEGER");

    int size = 0;
    for (auto& row : meta.data().items()) {
      if (row.key()[0] == '_') continue;
      size += mapping[row.value()];
    }
    meta.Add("_size", size);

    storage.Flush();
  }
  auto meta = storage.GetMetaData("some_table");
  int size = meta.data().at("_size");
  se::RawData raw(size);
  raw.Fill<int>(8)
     .Fill( std::string("Hello World and fuck u, peace of shit!") )
     .Fill<int>(255)
     .Fill<double>(128);
  storage.Write(meta, raw.data(), raw.capacity());
  std::cout << storage.Read(meta, 0, size) << std::endl;

//  storage.create("test", {
//      {"z", sql::DataType::INTEGER},
//      {"name", sql::DataType::TEXT}
//    });
//  storage.create("test_problem", {
//      {"id", sql::DataType::INTEGER},
//      {"id", sql::DataType::DOUBLE}
//    });
//
//  storage.insert("test", "7~hi");
//  storage.insert("test", "6~lolik");
//  storage.insert("hehe", "hih");
//  storage.insert("test_problem", "9~hih");
//
//  std::cout << storage.show_create("test") << std::endl;
//  std::cout << storage.show_create("test_problem") << std::endl;
//  std::cout << storage.select("test").dump() << std::endl;
//  std::cout << storage.select("test_problem").dump() << std::endl;

//  std::string canary = "canary";
//
//  se::MemoryBlock memoryBlock((uint8_t*)(canary.c_str()), canary.length());
//  std::ofstream fout("../database/testMemBlock.kp", std::ios::out | std::ios::binary);
//  if (fout.is_open())
//    std::cout << "opened" << std::endl;
//
//  fout << memoryBlock;
//  fout.close();
//  std::ifstream fin("../database/testMemBlock.kp", std::ios::in | std::ios::binary);
//  fin >> memoryBlock;
//  fin.close();
//  for (int i = 0; i < memoryBlock.size(); ++i)
//    std::cout << memoryBlock.data().get()[i];

//  btree::safe_btree_map<uint32_t, std::string> safeTree;
//  std::cout << safeTree.size() << std::endl;
//
//  std::ifstream fin("../database/tables.json");
//  se::MetaData j(fin);
//
//  std::cout << j.data().get()->dump() << std::endl;
//  j.data().get()->at("test") = "strTest";
//  std::cout << j.data().get()->dump() << std::endl;

//  storage.findMetaData("../database/test.kp");

  // storage.getMetaData("test");
  return 0;
}
