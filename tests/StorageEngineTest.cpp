#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdint>

#include "../src/backend/storage/StorageEngine.h"
#include "../src/backend/storage/datatypes/object.h"
#include "../src/backend/storage/datatypes/MemoryBlock.h"

int main(int argc, char *argv[])
{
//  auto& storage = se::StorageEngine::Instance();
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

  std::string canary = "canary";

  se::MemoryBlock memoryBlock((uint8_t*)(canary.c_str()), canary.length());
  std::ofstream fout("../database/testMemBlock.kp", std::ios::out | std::ios::binary);
  if (fout.is_open())
    std::cout << "opened" << std::endl;

  fout << memoryBlock;
  fout.close();
  std::ifstream fin("../database/testMemBlock.kp", std::ios::in | std::ios::binary);
  fin >> memoryBlock;
  fin.close();
  for (int i = 0; i < memoryBlock.size(); ++i)
    std::cout << memoryBlock.data().get()[i];

//  std::cout << storage.findMetaData("test").dump() << std::endl;
  return 0;
}
