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

#include <string>
#include <PassiveSocket.h>


namespace kappa
{

class Server
{
public:
  Server();


private:
  int port_ = 12564;

  // pthread_t          threadId;
  // struct thread_data thData;
  // CActiveSocket      client;
  // char result[1024];

  // thData.pszServerAddr = "127.0.0.1";
  // thData.nPort = 6789;
  // thData.nNumBytesToReceive = 1;
  // thData.nTotalPayloadSize = (int)strlen(TEST_PACKET);

  // pthread_create(&threadId, 0, CreateTCPEchoServer, &thData);
  // sleep(1); // allow a second for the thread to create and listen

  // client.Initialize();
  // client.SetNonblocking();

  // if (client.Open("127.0.0.1", 6789))
  // {
  //     if (client.Send((uint8 *)TEST_PACKET, strlen(TEST_PACKET)))
  //     {
  //         int numBytes = -1;
  //         int bytesReceived = 0;

  //         client.Select();

  //         while (bytesReceived != strlen(TEST_PACKET))
  //         {
  //             numBytes = client.Receive(MAX_PACKET);

  //             if (numBytes > 0)
  //             {
  //                 bytesReceived += numBytes;
  //                 memset(result, 0, 1024);
  //                 memcpy(result, client.GetData(), numBytes);
  //                 printf("received %d bytes: '%s'\n", numBytes, result);
  //             }
  //             else
  //             {
  //                 printf("Received %d bytes\n", numBytes);
  //             }
  //         }
  //     }
  // }
}

} // namespace kappa