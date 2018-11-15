#include "parser.hpp"
#include "flex-bison/flex_sql.hpp"
#include "flex-bison/bison_sql.hpp"


namespace sql {

void Parser::Process(const std::string& sql)
{

  yy::FlexScanner scanner;

  yy::BisonParser parser(scanner);
  int ret = parser.parse();
  if (ret != 0) {
    throw "SQLParser: Error!\n";
  }
}

} // namespace sql