#pragma once
#include <iostream>
#include "Screen.h"
#include "Global.h"
#include "ATMClient.h"

using namespace std;

class clsNormalWithdrawScreen : protected clsScreen
{
private:

    static int _ReadWithdrawAmount()
    {
        int Amount = 0;

        cout << "\nEnter an amount multiple of 5's > ";
        cin >> Amount;

        while (Amount <= 0 || Amount % 5 != 0)
        {
            cout << "\nInvalid amount.";
            cout << "\nEnter an amount multiple of 5's > ";
            cin >> Amount;
        }

        return Amount;
    }

    static void _PerformNormalWithdraw()
    {
        int Amount = _ReadWithdrawAmount();

        if (Amount > CurrentClient.AccountBalance())
        {
            cout << "\nThe amount exceeds your balance.";
            cout << "\nYour Balance is: " << CurrentClient.AccountBalance();
            return;
        }

        cout << "\nAre you sure you want to perform this transaction? y/n > ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (CurrentClient.Withdraw(Amount))
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

    static void ShowNormalWithdrawScreen()
    {
        system("cls");

        _DrawScreenHeader("\tNormal Withdraw Screen");

        _PerformNormalWithdraw();
    }
};