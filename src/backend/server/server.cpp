//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

#include "include/server.hpp"

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
  CActiveSocket* client = NULL;
  while (isRunning) {
    if ( (client = socket.Accept()) == NULL ) {
      continue;
    }    
    pool_.push(ProcessClient, std::ref(*this), client);
  }
}


static void Server::ProcessClient(int id, Server& srv, CActiveSocket* client)
{
  if (client->Receive(1) < 1) {
    client->Close();
    return;
  }

  switch (client->GetData()[0]) {

    case CONNECT:

      break;

    case CLOSE:

      break;

    case EXECUTE:
      std::string payload;
      int bytesRecv = 0;
      do {
        bytesRecv = client->Receive(bufferSize_);
        if (bytesRecv > 0) {
          std::string temp(client->GetData());
          payload.append(temp.begin(), temp.end());
        }
      } while (bytesRecv == bufferSize_);

      // send payload to parser
      // return result <---- client.Send

      break;

    case COMMIT:

      break;

    case ROLLBACK:

      break;

    case PREPARE:

      break;

    case BIND:

      break;

    default:
  }

  client->Close();

}

} // namespace kappa