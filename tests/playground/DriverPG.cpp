#include <string>
#include <driver/driver.hpp>
#include <iostream>
#include <exception>
#include <mutex>
#include <future>

int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );
  auto& instance = sql::Driver::Instance();

  try {
    std::cout << std::endl << instance.RunQuery("CREATE TABLE goods (id INTEGER, price DOUBLE, description TEXT)") << std::endl;
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  std::cout << std::endl << instance.RunQuery("SHOW TABLE goods") << std::endl;

  std::cout << std::endl << instance.RunQuery("INSERT INTO goods VALUES (123, 12.1, 'asd')") << std::endl;
  std::cout << std::endl << instance.RunQuery("INSERT INTO goods VALUES (777, 134.14, 'kek')") << std::endl;

  std::mutex m_printf;
  std::cout << std::endl << std::endl << "Thread-safety" << std::endl;
  auto task = [&m_printf](std::string path, int i) {
    auto& instance = sql::Driver::Instance();
    auto index = std::to_string(i);
    auto result = instance.RunQuery("INSERT INTO goods VALUES (" + index + ", 12.1, '" + index + "')");
    std::lock_guard<std::mutex> lock(m_printf);
    std::cout << std::endl << result << std::endl;
  };
  auto t1 = std::async(std::launch::async, task, argv[0], 12);
  auto t2 = std::async(std::launch::async, task, argv[0], 13);
  t1.wait(); t2.wait();

  std::cout << std::endl << instance.RunQuery(
      std::string("UPDATE goods SET description='Updated!' WHERE id > 130;")
      +
      std::string("DELETE from goods where id < 100;")
    ) << std::endl;

  std::cout << std::endl << instance.RunQuery("SELECT * FROM goods") << std::endl;
  std::cout << std::endl << instance.RunQuery("SELECT id, description FROM goods") << std::endl;
  std::cout << std::endl << instance.RunQuery("SELECT 322, -id, +id, price * 10, NOT description FROM goods") << std::endl;
  std::cout << std::endl << instance.RunQuery("SELECT description FROM goods WHERE id < 200") << std::endl;

  std::cout << std::endl << instance.RunQuery("DROP TABLE goods") << std::endl;
  return 0;
}
