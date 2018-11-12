#include <string>

#include "../src/backend/parser/parser.hpp"


int main(int argc, char *argv[])
{
  std::string s;
  auto& parser = sql::Parser::Instance();

  s = "Drop table t";
  parser.Process(s);

  s = "show table stud";
  parser.Process(s);

  s = "CREATE TABLE students (name TEXT) ";
  parser.Process(s);

  s = "CREATE TABLE students (id Text, id1 TEXT, idddd TEXT) ; ";
  parser.Process(s);

  s = "CREATE TABLE students (id DOUBLE) ; ";
  parser.Process(s);

  s = "CREATE TABLE students (id INTEGER)";
  parser.Process(s);

  return 0;
}