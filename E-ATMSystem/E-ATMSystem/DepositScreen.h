#pragma once
#include <iostream>
#include "Screen.h"
#include "Global.h"
#include "ATMClient.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private:

    static double _ReadDepositAmount()
    {
        double Amount = 0;

        cout << "\nEnter a positive Deposit Amount > ";
        cin >> Amount;

        while (Amount <= 0)
        {
            cout << "\nInvalid amount.";
            cout << "\nEnter a positive Deposit Amount > ";
            cin >> Amount;
        }

        return Amount;
    }

    static void _PerformDeposit()
    {
        double Amount = _ReadDepositAmount();

        cout << "\nAre you sure you want to perform this transaction? y/n > ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (CurrentClient.Deposit(Amount))
            {
                cout << "\nDone Successfully.";
                cout << "\nNew Balance is: "
                    << CurrentClient.AccountBalance();
            }
            else
            {
                cout << "\nTransaction failed.";
            }
        }
        else
        {
            cout << "\nTransaction cancelled.";
        }
    }

public:

    static void ShowDepositScreen()
    {
        system("cls");

        _DrawScreenHeader("\tDeposit Screen");

        _PerformDeposit();
    }
};