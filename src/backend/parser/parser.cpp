#include "parser.hpp"
#include "flex-bison/flex_sql.h"
#include "flex-bison/bison_sql.h"


namespace sql {

void Parser::Process(const std::string& sql)
{
  yyscan_t scanner;
  // YY_BUFFER_STATE state;

  if (yylex_init(&scanner)) {
    // Couldn't initialize the lexer.
    throw "SQLParser: Error when initializing lexer!\n";
  }

  auto state = yy_scan_string(sql.c_str(), scanner);

  int ret = yyparse(scanner);
  if (ret != 0) {
    throw "SQLParser: Error!\n";
  }

  yy_delete_buffer(state, scanner);
  yylex_destroy(scanner);
}

} // namespace sql