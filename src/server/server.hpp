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
#include <exception>
#include <string>
#include <thread>
#include <memory>
#include <utility>
#include <map>

#include <ctpl_stl.h>
#include <driver/driver.hpp>
#include <protocol.hpp>

#include <ActiveSocket.h>
#include <PassiveSocket.h>

namespace kappa
{

using client_s = std::shared_ptr<CActiveSocket>;
using client_w = std::weak_ptr<CActiveSocket>;
using client_u = std::unique_ptr<CActiveSocket>;

class Server
{
public:
  Server(int = 12564, int = 4096);
  ~Server();

  /**
   * Method to start server.
   * It would block current thread by listening server's socket.
   */
  void Run();

  /**
   * Get bufferSize property
   * 
   * @return int
   */
  int const& bufferSize() const;


  /**
   * Set bufferSize property
   * 
   * @param int Size of buffer to set.
   */
  void bufferSize(int const&);

private:
  bool isRunning = true;
  int port_;
  int bufferSize_;
  ctpl::thread_pool pool_; 
  CPassiveSocket socket_;
  std::map<client_s, int> clients_;

  /**
   * Registers new client and pushes task to threadPool for its processing.
   *
   * @param std::shared<CActiveSocket> Smart-pointer to client object.
   */
  void RegisterClient(client_s);

  /**
   * Registers new client and pushes task to threadPool for its processing.
   *
   * @param std::shared<CActiveSocket> Smart-pointer to client object.
   */
  void RemoveClient(client_s);

  /**
   * Function for client processing.
   *
   * @param std::shared<CActiveSocket> Smart-pointer to client object.
   */
  void ProcessClient(client_s);
};

} // namespace kappa