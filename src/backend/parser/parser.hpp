#pragma once

#include <vector>
#include <string>

#include "flex-bison/bison_sql.hpp"
#include "flex-bison/flex_sql.hpp"
#include "flex-bison/location.hh"

#include "sql.hpp"

namespace sql {

class Parser
{
public:
  static Parser& Instance()
  {
    static Parser instance;
    return instance;
  }

  /**
   * Parses SQL-request and returns tree of commands to execute
   *
   * @param std::string& SQL-request to process
   * @return sql::Command
   */
  std::vector<std::shared_ptr<cmd::Instruction>> Process(const std::string&);

private:
  Parser() = default;
  ~Parser() = default;
  Parser(Parser const &) = delete;
  void operator=(Parser const &) = delete;

  friend class yy::BisonParser;
  friend class yy::FlexScanner;

  void AddInstruction(const std::shared_ptr<cmd::Instruction>&);

  std::vector<std::shared_ptr<cmd::Instruction>> trees_;
  bool trace_ = true;
};

} // namespace sql