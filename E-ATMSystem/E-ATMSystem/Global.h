#pragma once
#include <vector>
#include "ATMClient.h"
#include <string>
clsATMClient CurrentClient = clsATMClient::GetEmptyClientObject();

struct stTransaction
{
    string Operation;
    double Amount;
    double BalanceAfter;
};

extern vector<stTransaction> SessionTransactions;