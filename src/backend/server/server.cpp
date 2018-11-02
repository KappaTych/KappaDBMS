//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

#include "../include/server.hpp"

namespace kappa {

Server::Server(int port, int size)
    : port_(port),
      bufferSize_(size),
      socket_(),
      pool_( std::thread::hardware_concurrency() )
{
  socket_.Initialize();
  socket_.Listen("0.0.0.0", port_);
}

Server::~Server()
{
  socket_.Close();
}

int const& Server::bufferSize() const
{
  return bufferSize_;
}

void Server::bufferSize(int const& size)
{
  bufferSize_ = size;
}

void Server::Run()
{
  std::cout << "Server is running, port: " << port_ << std::endl;

  CActiveSocket* client = NULL;
  while (isRunning) {
    if ( (client = socket_.Accept()) == NULL ) {
      continue;
    }
    pool_.push(ProcessRequest, std::ref(*this), client);
  }
}


void Server::ProcessRequest(int id, Server& srv, CActiveSocket* client)
{
  if (client->Receive(1) < 1) {
    client->Close();
    return;
  }

  int bytesRecv = 0;
  std::string payload;

  switch (client->GetData()[0]) {

    case cmd::CONNECT:

      break;

    case cmd::CLOSE:

      break;

    case cmd::EXECUTE:
      do {
        bytesRecv = client->Receive(srv.bufferSize());
        if (bytesRecv > 0) {
          std::string temp( (char*)(client->GetData()) );
          payload.append(temp.begin(), temp.end());
        }
      } while (bytesRecv == srv.bufferSize());

      std::cout << "Received: " << payload << std::endl;

      // send payload to parser
      // return result <---- client.Send
      break;

    case cmd::COMMIT:

      break;

    case cmd::ROLLBACK:

      break;

    case cmd::PREPARE:

      break;

    case cmd::BIND:

      break;

  }

  client->Close();
}

} // namespace kappa