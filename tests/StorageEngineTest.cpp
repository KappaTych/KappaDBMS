#include <iostream>
#include "../src/backend/storage/StorageEngine.h"
#include "../src/backend/storage/datatypes/object.h"

int main()
{
  se::StorageEngine::getInstance().create("test", {{"z",   dt::DataType::INTEGER},
                                                   {"name", dt::DataType::TEXT}});
  se::StorageEngine::getInstance().create("test_problem", {{"id", dt::DataType::INTEGER},
                                                           {"id", dt::DataType::DOUBLE}});

//  std::cout << se::StorageEngine::getInstance().show_create("test") << std::endl;
//  std::cout << se::StorageEngine::getInstance().show_create("test_problem") << std::endl;
}
