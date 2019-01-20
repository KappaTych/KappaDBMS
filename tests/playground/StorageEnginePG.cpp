#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdint>
#include <btree/safe_btree_map.h>

#include <unordered_map>
#include <string>

#include <storage/StorageEngine.hpp>
#include <storage/datatypes/RawData.hpp>


int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );
  auto& storage = se::StorageEngine::Instance();

  // Supported types info
  std::unordered_map<std::string, se::size_t> mapping = {
    {"INTEGER", sizeof(int32_t)},
    {"TEXT", se::STRING_LEN},
  };

  std::string tableName = "some_table";

  if (!storage.HasMetaData(tableName)) {
    // CREATE TABLE
    auto& meta = storage.CreateData(tableName);
    meta.Add("id", "INTEGER");
    meta.Add("name", "TEXT");
    meta.Add("count", "INTEGER");

    se::size_t size = 0;
    for (auto& row : meta.data().at("public").items()) {
      size += mapping[row.value()];
    }
    meta.Add("size", size, "private");

    storage.Flush();
  }

  // INSERT INTO
  auto& meta = storage.GetMetaData(tableName);
  se::size_t size = meta.data()["private"]["size"];
  se::RawData raw(size);

  raw.Fill<int32_t>(1)
     .Fill<std::string>("First Line")
     .Fill<int32_t>(64);
  storage.Write(meta, raw.data(), raw.capacity());

  raw.FullReset()
     .Fill<int32_t>(2)
     .Fill<std::string>("Second line!")
     .Fill<int32_t>(16);
  storage.Write(meta, raw.data(), raw.capacity());

  raw.FullReset()
     .Fill<int32_t>(3)
     .Fill<std::string>("Third line!")
     .Fill<int32_t>(16);
  storage.Write(meta, raw.data(), raw.capacity());

  // SELECT *
  std::cout << "SELECT ALL" << std::endl;
  auto dataAll1 = storage.Read(meta, size);
  for (auto& x : dataAll1) {
    std::cout << x.Get<int32_t>() << std::endl;
    std::cout << x.Get<std::string>() << std::endl;
    std::cout << x.Get<int32_t>() << std::endl << "-----------------------" << std::endl;
    x.Reset();
  }

  // SELECT * WHERE id = 2
  std::cout << "SELECT WHERE id = 2" << std::endl;
  auto dataWhere = storage.Read(meta, size, [](const se::RawData& raw) {
      return (raw.Get<int>() == 2);
    });
  for (auto& x : dataWhere) {
    std::cout << x.Get<int32_t>() << std::endl;
    std::cout << x.Get<std::string>() << std::endl;
    std::cout << x.Get<int32_t>() << std::endl << "-----------------------" << std::endl;
    x.Reset();
  }

  // UPDATE WHERE id = 1
  std::cout << "UPDATE WHERE id = 1" << std::endl << "-----------------------" << std::endl;
  storage.Update(meta, size, [](se::RawData&& raw) {
      if (raw.Get<int>() == 1) {
        raw.Fill<std::string>("Updated first line!", true);
        return true;
      }
      return false;
    });

  // DELETE WHERE count < 64
  std::cout << "DELETE WHERE count < 64" << std::endl << "-----------------------" << std::endl;
  storage.Delete(meta, size, [](const se::RawData& raw) {
      return (raw.Skip<int>().Skip<std::string>(se::STRING_LEN).Get<int>() < 64);
    });

  // SELECT *
  std::cout << "SELECT ALL" << std::endl;
  auto dataAll2 = storage.Read(meta, size);
  for (auto& x : dataAll2) {
    std::cout << x.Get<int32_t>() << std::endl;
    std::cout << x.Get<std::string>() << std::endl;
    std::cout << x.Get<int32_t>() << std::endl << "-----------------------" << std::endl;
    x.Reset();
  }

  // DROP TABLE
  storage.RemoveData(tableName);


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
