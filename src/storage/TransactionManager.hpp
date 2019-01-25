#pragma once

#include <atomic>

class TransactionManager {
public:
  static TransactionManager& Instance()
  {
    static TransactionManager instance;
    return instance;
  }
  void operator=(TransactionManager const &) = delete;

  uint64_t NewTransaction();
  static constexpr auto NO_TRANSACTION = false;

private:
  TransactionManager();
  ~TransactionManager() = default;

  std::atomic<uint64_t> nextTransactionId;
  static constexpr uint64_t INIT_TRANSACTION_ID = 1;
};