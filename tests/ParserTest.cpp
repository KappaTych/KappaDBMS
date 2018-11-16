#include <string>

#include "../src/backend/parser/parser.hpp"


int main(int argc, char *argv[])
{
  std::string s;
  auto& parser = sql::Parser::Instance();

  s = "Drop table t;";
  auto tree = parser.Process(s);

  s = "show table stud";
  tree = parser.Process(s);

  s = "CREATE TABLE students (name TEXT) ";
  tree = parser.Process(s);

  s = "CREATE TABLE students (id Text, id1 TEXT, idddd TEXT) ; ";
  tree = parser.Process(s);

  s = "CREATE TABLE students (id DOUBLE) ; ";
  tree = parser.Process(s);

  s = "CREATE TABLE students (id INTEGER)";
  tree = parser.Process(s);

  s = "SElECT * from t";
  tree = parser.Process(s);

  s = "select a, b, c from t";
  tree = parser.Process(s);

  s = "select * from t where t == ee;";
  tree = parser.Process(s);

  s = "select * from t where t == 'dd'";
  tree = parser.Process(s);

  s = "select * from t where t > 900.02";
  tree = parser.Process(s);

  s = "select * from t where t > 900";
  tree = parser.Process(s);

  s = "insert into table_name values (123, 'test', 12.1); ";
  tree = parser.Process(s);

  s = "insert into table_name field1, field2 values ('1', '2');";
  tree = parser.Process(s);

  s = "delete from table_name";
  tree = parser.Process(s);

  s = "update table_name set field2 = 12, field3 = 'dd', field4 = 12.1";
  tree = parser.Process(s);

  s = "update table_name set field2 = 12, field3 = 'dd' where t > 0";
  tree = parser.Process(s);

  return 0;
}