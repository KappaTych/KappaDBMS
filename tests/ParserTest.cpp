#include <string>
#include "src/backend/parser/parser.hpp"

int main(int argc, char *argv[]) {
  std::string s = "Drop table t";
  sql::sqliteParse(s);

  s = "show table stud";
  sql::sqliteParse(s);

  s = "CREATE TABLE students (name TEXT) ";
  sql::sqliteParse(s);

  s = "CREATE TABLE students (id Text, id1 TEXT, idddd TEXT) ; ";
  sql::sqliteParse(s);

  s = "CREATE TABLE students (id DOUBLE) ; ";
  sql::sqliteParse(s);

  s = "CREATE TABLE students (id INTEGER)";
  sql::sqliteParse(s);
}