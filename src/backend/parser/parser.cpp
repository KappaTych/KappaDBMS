#include "parser.h"

#include "flex-bison/bison_sql.h"
#include "flex-bison/flex_sql.h"
#include <string>

namespace sql {

void sqliteParse(const std::string &sql) {
  yyscan_t scanner;
  YY_BUFFER_STATE state;

  if (yylex_init(&scanner)) {
    // Couldn't initialize the lexer.
    throw "SQLParser: Error when initializing lexer!\n";
  }

  const char *text = sql.c_str();
  state = yy_scan_string(text, scanner);

  int ret = yyparse(scanner);
  if (ret != 0) { 
    throw "SQLParser: Error!\n"; 
  }

  yy_delete_buffer(state, scanner);
  yylex_destroy(scanner);
}

} // namespace sql
