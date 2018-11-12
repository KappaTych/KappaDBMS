#include "parser.hpp"
#include "flex-bison/flex_sql.hpp"
#include "flex-bison/bison_sql.hpp"


namespace sql {

void Parser::Process(const std::string& sql)
{

  yy::FlexScanner scanner;

  yy::BisonParser parser(scanner, *this);
  int ret = parser.parse();
  if (ret != 0) {
    throw "SQLParser: Error!\n";
  }
}

void Parser::addInstruction(const std::shared_ptr<cmd::Instruction>& instruction)
{
  trees_.push_back(instruction);
}

} // namespace sql