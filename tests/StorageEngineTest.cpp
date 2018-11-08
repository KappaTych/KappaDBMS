#include <iostream>
#include <fstream>
#include <cstdio>
#include "../src/backend/storage/StorageEngine.h"
#include "../src/backend/storage/datatypes/object.h"

int main()
{
//  se::StorageEngine::getInstance().create("test", {{"z",   dt::DataType::INTEGER},
//                                                   {"name", dt::DataType::TEXT}});
//  se::StorageEngine::getInstance().create("test_problem", {{"id", dt::DataType::INTEGER},
//                                                           {"id", dt::DataType::DOUBLE}});

  se::StorageEngine::getInstance().insert("test", "5~hello");
  se::StorageEngine::getInstance().insert("test", "6~lolik");
  se::StorageEngine::getInstance().insert("hehe", "hih");

//  std::cout << se::StorageEngine::getInstance().show_create("test") << std::endl;
//  std::cout << se::StorageEngine::getInstance().show_create("test_problem") << std::endl;
  return 0;
}
