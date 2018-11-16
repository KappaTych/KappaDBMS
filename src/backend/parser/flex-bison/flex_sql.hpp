#pragma once

#include "../parser.hpp"
#include <sstream>
#include "bison_sql.hpp"


#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::BisonParser::symbol_type yy::FlexScanner::get_next_token()


namespace yy {


class FlexScanner : public yyFlexLexer {
 public:
  FlexScanner(std::string str) : buffer(str)
  {
    yyFlexLexer::switch_streams(&buffer, nullptr);
  };

  ~FlexScanner() override = default;

  virtual yy::BisonParser::symbol_type get_next_token();

 private:
  yy::location loc;
  std::istringstream buffer;

};

}
