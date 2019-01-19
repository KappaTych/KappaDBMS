//
// Kappa Database Management System
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

#include <iostream>

#include <cxxopts.hpp>
#include <storage/StorageEngine.hpp>
#include <server/server.hpp>

int main(int argc, char *argv[])
{
  se::StorageEngine::SetRootPath( cppfs::FilePath(argv[0]).directoryPath() );

  try {
    cxxopts::Options options(argv[0], "Server Application for Kappa Database Management System");
    options
      .positional_help("[optional args]")
      .show_positional_help();

    options.add_options()
      ("h,help", "Show help")
      ("s,size", "Set size of buffer per client", cxxopts::value<int>()->default_value("4096"), "INT")
      ("p,port", "Set server port", cxxopts::value<int>()->default_value("12564"), "PORT");

    auto result = options.parse(argc, argv);

    if (result.count("h")) {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    kappa::Server server(result["p"].as<int>(), result["s"].as<int>());

    std::cout << "Starting server..." << std::endl;
    server.Run();

  } catch (const cxxopts::OptionException& e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit(1);
  }

  return 0;
}