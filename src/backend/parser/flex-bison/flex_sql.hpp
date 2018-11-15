#pragma once

#include "../parser.hpp"

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::BisonParser::symbol_type yy::FlexScanner::get_next_token()

#include "bison_sql.hpp"

namespace yy {


class FlexScanner : public yyFlexLexer {
 public:
  FlexScanner() = default;
  ~FlexScanner() = default;
  virtual yy::BisonParser::symbol_type get_next_token();

 private:
  yy::location loc;
};

}
