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

namespace packet
{

const char CLOSE    = 0x00;
const char CONNECT  = 0x01;
const char EXECUTE  = 0x02;
const char COMMIT   = 0x03;
const char ROLLBACK = 0x04;
const char PREPARE  = 0x05;
const char BIND     = 0x06;

} // namespace server