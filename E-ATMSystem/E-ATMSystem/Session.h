#pragma once
#include <iostream>
#include <string>
#include "Global.h"
class clsSession
{
public:

    static void AddTransaction(string Operation, double Amount, double BalanceAfter)
    {
        SessionTransactions.push_back(  Operation + "|" +   to_string(Amount) + "|" +  to_string(BalanceAfter));
    }
    static void Clear()
    {
        SessionTransactions.clear();
    }
};