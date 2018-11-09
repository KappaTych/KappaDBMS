//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

#include "server.hpp"


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
  std::cout << "Server is running. Port: " << port_ << std::endl;

  client_s client = NULL;
  while (isRunning) {
    if ( (client = client_s(socket_.Accept())) == NULL ) {
      continue;
    }
    pool_.push([&, this](int id){ ProcessClient(client); });
  }
}

void Server::RegisterClient(client_s client)
{
  clients_.emplace( std::make_pair(std::move(client), 0) );
  // TODO: make ping / pulse-request for checkin user is online.
}

void Server::RemoveClient(client_s client)
{
  clients_.erase( std::move(client) );
}

void Server::ProcessClient(client_s client)
{
  if (client->Receive(1) < 1) {
    client->Close();
    return;
  }

  int bytesRecv = 0;
  std::string payload;
  std::string result;
  payload.reserve(bufferSize_ << 2);

  switch (client->GetData()[0]) {

    case cmd::CONNECT:
      RegisterClient(client);
      return;

    case cmd::CLOSE:
      RemoveClient(client);
      return;

    case cmd::EXECUTE:
      do {
        bytesRecv = client->Receive(bufferSize_);
        if (bytesRecv > 0) {
          std::string temp( (char*)(client->GetData()) );
          // std::cout << "Received: " << temp << std::endl << std::endl;
          payload.append(temp.begin(), temp.end());
        }
      } while (bytesRecv == bufferSize_);
      std::cout << "Received: " << payload << std::endl;

      try {
        sql::sqliteParse(payload);
        result = "Okay, SQL accepted";
      } catch (std::string ex) {
        result = ex;
      } catch (...) {
        result = "Unexpected error";
      }
      client->Send((const uint8*) result.c_str(), result.length());
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

  client->Close(); // TODO: it must be done only if user isn't authenticated.
}

} // namespace kappa