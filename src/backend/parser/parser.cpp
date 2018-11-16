#include "parser.hpp"
#include "flex-bison/flex_sql.hpp"
#include "flex-bison/bison_sql.hpp"


namespace sql {

std::vector<std::shared_ptr<cmd::Instruction>> Parser::Process(const std::string& sql)
{
  yy::FlexScanner scanner(sql);
  scanner.set_debug(trace_);

  yy::BisonParser parser(scanner, *this);
  parser.set_debug_level(trace_);

  trees_.clear();

  int ret = parser.parse();

  if (ret != 0) {
    throw "SQLParser: Error!\n";
  }

  return trees_;
}

void Parser::AddInstruction(const std::shared_ptr<cmd::Instruction>& instruction)
{
  trees_.push_back(instruction);
}

} // namespace sql