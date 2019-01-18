#include <string>
#include <driver/driver.hpp>
#include <iostream>
#include <exception>


int main(int argc, char *argv[])
{
  auto& instance = sql::Driver::Instance();

  try {
      std::string create_query = "CREATE TABLE users20 (id INTEGER, price DOUBLE, description TEXT);";
      std::cout << instance.RunQuery(create_query) << std::endl;
  }
  catch (std::exception& ex) {
      std::cout << ex.what() << std::endl;
  }

  std::string show_query = "SHOW TABLE users20";
  std::cout << instance.RunQuery(show_query) << std::endl;

  std::string insert_query( "insert into users20 values (123, 'test', 12.1); ");
  std::cout << instance.RunQuery(insert_query) << std::endl;
  return 0;
}