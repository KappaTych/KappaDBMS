#include <string>
#include <driver/driver.hpp>
#include <iostream>
#include <exception>

int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );
  auto& instance = sql::Driver::Instance();

//  try {
//    std::string create_query = "CREATE TABLE goods (id INTEGER, price DOUBLE, description TEXT)";
//    std::cout << instance.RunQuery(create_query) << std::endl;
//  } catch (std::exception& ex) {
//    std::cout << ex.what() << std::endl;
//  }
//
//  std::string show_query = "SHOW TABLE goods";
//  std::cout << instance.RunQuery(show_query) << std::endl;
//
  std::string insert_query( "INSERT INTO goods VALUES (123, 12.1, 'asd')");
  std::cout << instance.RunQuery(insert_query) << std::endl;

  std::string insert2_query( "INSERT INTO goods VALUES (777, 134.14, 'kek')");
  std::cout << instance.RunQuery(insert2_query) << std::endl;

  std::string select_query = "SELECT * FROM goods";
  std::cout << instance.RunQuery(select_query) << std::endl;

//  std::string drop_query = "DROP TABLE goods";
//  std::cout << instance.RunQuery(drop_query) << std::endl;
  return 0;
}