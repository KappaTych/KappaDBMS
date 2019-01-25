//
// Created by cheri on 1/25/19.
//

#include "TransactionManager.hpp"

TransactionManager::TransactionManager() : nextTransactionId(INIT_TRANSACTION_ID) {}

uint64_t TransactionManager::NewTransaction()
{
    return nextTransactionId++;
}