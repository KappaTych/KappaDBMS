#include <string>
#include <driver/driver.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  auto& instance = sql::Driver::Instance();
  std::string create_query = "CREATE TABLE users9 (id Text, id1 INTEGER);";
  std::cout << instance.RunQuery(create_query) << std::endl;

  std::string show_query = "SHOW TABLE users9";
  std::cout << instance.RunQuery(show_query) << std::endl;
  return 0;
}