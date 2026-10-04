#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

std::string getDateTime();

void addTransaction(
    long long accountNo,
    std::string type,
    double amount,
    double balance
);

void miniStatement(long long accountNo);

#endif