#include <iostream>
#include <fstream>
#include <cstdio>

#include "../src/backend/storage/StorageEngine.h"
#include "../src/backend/storage/datatypes/object.h"

int main()
{
  auto& storage = se::StorageEngine::Instance();
//  storage.create("test", {{"z",   dt::DataType::INTEGER},
//                                                   {"name", dt::DataType::TEXT}});
//  storage.create("test_problem", {{"id", dt::DataType::INTEGER},
//                                                           {"id", dt::DataType::DOUBLE}});

//  storage.insert("test", "5~hello");
//  storage.insert("test", "6~lolik");
//  storage.insert("hehe", "hih");
  storage.insert("test_problem", "9~hih");

//  std::cout << storage.show_create("test") << std::endl;
//  std::cout << storage.show_create("test_problem") << std::endl;
  std::cout << (storage.select("test")).dump();
  std::cout << (storage.select("test_problem")).dump();
  return 0;
}
