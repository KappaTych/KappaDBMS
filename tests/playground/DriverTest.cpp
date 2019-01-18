#include <string>
#include <driver/driver.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );
  auto& instance = sql::Driver::Instance();

  std::string create_query = "CREATE TABLE my_table (name TEXT, id INTEGER)";
  std::cout << instance.RunQuery(create_query) << std::endl;

  std::string show_query = "SHOW TABLE my_table";
  std::cout << instance.RunQuery(show_query) << std::endl;

  std::string insert_query = "INSERT INTO my_table VALUES('Text', 20)";
  std::cout << instance.RunQuery(insert_query) << std::endl;

  std::string select_query = "SELECT * FROM my_table";
  std::cout << instance.RunQuery(select_query) << std::endl;

  std::string drop_query = "DROP TABLE my_table";
  std::cout << instance.RunQuery(drop_query) << std::endl;
  return 0;
}