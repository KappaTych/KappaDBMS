//
// protocol.hpp
// ~~~~~~~~~~~~
//
// Copyright (c) 2018-2019 Vitaliy E. Palchevskii [@abelidze]
//
// Distributed under the Apache License, Version 2.0. (See accompanying
// file LICENSE or copy at http://www.apache.org/licenses/LICENSE-2.0.txt)
//

namespace kappa {

enum cmd {
  CLOSE    = 0x00,
  CONNECT  = 0x01,
  EXECUTE  = 0x02,
  COMMIT   = 0x03,
  ROLLBACK = 0x04,
  PREPARE  = 0x05,
  BIND     = 0x06
};

} // namespace kappa
