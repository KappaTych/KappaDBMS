#include <string>
#include <driver/driver.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  auto& instance = sql::Driver::Instance();
  std::string query = "CREATE TABLE students (id Text, id1 TEXT, idddd TEXT);"; 
  std::cout << instance.RunQuery(query) << std::endl;
  return 0;
}