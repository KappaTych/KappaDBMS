//
// server.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

#pragma once

#include <iostream>
#include <string>
#include <thread>

#include <ctpl_stl.h>
#include <ActiveSocket.h>
#include <PassiveSocket.h>

#include "protocol.hpp"


namespace kappa
{

class Server
{
public:
  Server(int = 12564, int = 4096);
  ~Server();

  static void ProcessRequest(int, Server&, CActiveSocket*);
  void Run();

  int const& bufferSize() const;
  void bufferSize(int const&);

private:
  bool isRunning = true;
  int port_;
  int bufferSize_;
  ctpl::thread_pool pool_; 
  CPassiveSocket socket_;
};

} // namespace kappa