#pragma once

#include <vector>
#include <string>

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
  void Process(const std::string&);

private:
  Parser() = default;
  ~Parser() = default;
  Parser(Parser const &) = delete;
  void operator=(Parser const &) = delete;
}

} // namespace sql