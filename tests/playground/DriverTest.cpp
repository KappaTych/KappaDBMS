#include <string>
#include <driver/driver.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  auto& instance = sql::Driver::Instance();
  std::string query = "CREATE TABLE users"; 
  std::cout << instance.RunQuery(query) << std::endl;
  return 0;
}