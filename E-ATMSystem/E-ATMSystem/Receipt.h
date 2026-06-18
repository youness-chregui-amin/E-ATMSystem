#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Global.h"

using namespace std;

class clsReceipt
{
public:

    static void AddTransaction(string Operation, double Amount)
    {
        stTransaction Transaction;

        Transaction.Operation = Operation;
        Transaction.Amount = Amount;
        Transaction.BalanceAfter = CurrentClient.AccountBalance();

        SessionTransactions.push_back(Transaction);
    }

    static void SaveReceipt()
    {
        fstream File;
        File.open("Receipt.txt", ios::out); // overwrite old receipt

        if (!File.is_open())
            return;

        File << "========================================\n";
        File << "              ATM RECEIPT               \n";
        File << "========================================\n\n";

        File << "Client Name    : " << CurrentClient.Name() << endl;
        File << "Account Number : " << CurrentClient.AccountNumber() << endl;

        File << "\n----------------------------------------\n";

        if (SessionTransactions.empty())
        {
            File << "No transactions in this session.\n";
        }
        else
        {
            for (short i = 0; i < SessionTransactions.size(); i++)
            {
                File << "Transaction [" << i + 1 << "]\n";
                File << "Operation     : " << SessionTransactions[i].Operation << endl;
                File << "Amount        : " << fixed << setprecision(2)
                    << SessionTransactions[i].Amount << endl;
                File << "Balance After : " << fixed << setprecision(2)
                    << SessionTransactions[i].BalanceAfter << endl;
                File << "----------------------------------------\n";
            }
        }

        File << "\n========================================\n";
        File << "        Thank you for using E-ATM        \n";
        File << "========================================\n";

        File.close();

        cout << "\nReceipt saved successfully in Receipt.txt\n";
    }
};