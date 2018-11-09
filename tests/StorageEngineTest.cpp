#include <iostream>
#include <fstream>
#include <cstdio>

#include "../src/backend/storage/StorageEngine.h"
#include "../src/backend/storage/datatypes/object.h"

int main(int argc, char *argv[])
{
  auto& storage = se::StorageEngine::Instance();
  storage.create("test", {
      {"z", sql::DataType::INTEGER},
      {"name", sql::DataType::TEXT}
    });
  storage.create("test_problem", {
      {"id", sql::DataType::INTEGER},
      {"id", sql::DataType::DOUBLE}
    });

  storage.insert("test", "5~hello");
  storage.insert("test", "6~lolik");
  storage.insert("hehe", "hih");
  storage.insert("test_problem", "9~hih");

  std::cout << storage.show_create("test") << std::endl;
  std::cout << storage.show_create("test_problem") << std::endl;
  std::cout << storage.select("test").dump() << std::endl;
  std::cout << storage.select("test_problem").dump() << std::endl;
  return 0;
}
