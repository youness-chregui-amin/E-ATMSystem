#pragma once
#include <iostream>
#include "Screen.h"
#include "Global.h"
#include "ATMClient.h"
#include "InputValidate.h"
#include "Receipt.h"

using namespace std;

class clsQuickWithdrawScreen : protected clsScreen
{
private:

    enum enQuickWithdrawOptions
    {
        e20 = 1,
        e50 = 2,
        e100 = 3,
        e200 = 4,
        e400 = 5,
        e600 = 6,
        e800 = 7,
        e1000 = 8,
        eExit = 9
    };

    static short _ReadQuickWithdrawOption()
    {
        short Choice = 0;

        
            cout << setw(37) << left << "" << "\t\nChoose what to do from [1] to [9] > ";
            Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? > ");


        return Choice;
    }

    static short _GetQuickWithdrawAmount(enQuickWithdrawOptions Option)
    {
        switch (Option)
        {
        case e20:
            return 20;
        case e50:
            return 50;
        case e100:
            return 100;
        case e200:
            return 200;
        case e400:
            return 400;
        case e600:
            return 600;
        case e800:
            return 800;
        case e1000:
            return 1000;
        default:
            return 0;
        }
    }

    static void _PerformQuickWithdrawOption(enQuickWithdrawOptions Option)
    {
        if (Option == eExit)
            return;

        short Amount = _GetQuickWithdrawAmount(Option);

        if (Amount > CurrentClient.AccountBalance())
        {
            cout << "\nThe amount exceeds your balance.";
            cout << "\nPlease choose another amount.\n";
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
                cout << "\nNew Balance is: "  << CurrentClient.AccountBalance();
                clsReceipt::AddTransaction( "Quick Withdraw", Amount);
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

    static void ShowQuickWithdrawScreen()
    {
        system("cls");

        _DrawScreenHeader("\tQuick Withdraw Screen");
        cout << setw(34) << left << "" << "+----------------------------------------------+\n";
        cout << setw(34) << left << "" << "|              QUICK WITHDRAW MENU             |\n";
        cout << setw(34) << left << "" << "+----------------------------------------------+\n";
        cout << setw(34) << left << "" << "|  [1]  20  USD       |  [2]  50   USD         |\n";
        cout << setw(34) << left << "" << "|  [3]  100 USD       |  [4]  200  USD         |\n";
        cout << setw(34) << left << "" << "|  [5]  400 USD       |  [6]  600  USD         |\n";
        cout << setw(34) << left << "" << "|  [7]  800 USD       |  [8]  1000 USD         |\n";
        cout << setw(34) << left << "" << "|                                              |\n"; 
        cout << setw(34) << left << "" << "|                [9]  Exit                     |\n";
        cout << setw(34) << left << "" << "+----------------------------------------------+\n";
        cout << setw(34) << left << "" << "|  Current Balance: " << setw(25) << left   << CurrentClient.AccountBalance() << "  |\n";
        cout << setw(34) << left << "" << "+----------------------------------------------+\n";

   _PerformQuickWithdrawOption( (enQuickWithdrawOptions)_ReadQuickWithdrawOption() );
    }
};