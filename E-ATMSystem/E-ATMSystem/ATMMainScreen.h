#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "QuickWithdrawScreen.h"
#include "NormalWithdrawScreen.h"
#include "DepositScreen.h"
#include "CheckBalanceScreen.h"
#include "InputValidate.h"
#include "Receipt.h"
using namespace std;

class clsATMMainScreen : protected clsScreen
{
private:

    enum enATMMainMenuOptions
    {
        eQuickWithdraw = 1,
        eNormalWithdraw = 2,
        eDeposit = 3,
        eCheckBalance = 4,
        eLogout = 5
    };

    static short _ReadATMMainMenuOption()
    {
        short Choice = 0;

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] > ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? > ");

        return Choice;
    }
 
    static void _ShowQuickWithdrawScreen()
    {

        clsQuickWithdrawScreen::ShowQuickWithdrawScreen();

    }
    static void _ShowNormalWithdrawScreen()
    {

        clsNormalWithdrawScreen::ShowNormalWithdrawScreen();

    }
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();

    }
    static void _ShowCheckBalanceScreen()
    {

        clsCheckBalanceScreen::ShowCheckBalanceScreen();


    }
    static void _GoBackToATMMainMenu()
    {
        cout << "\n\nPress any key to go back to ATM Main Menu...";
        system("pause>0");

        ShowATMMainMenu();
    }

    static void _PerformATMMainMenuOption(enATMMainMenuOptions Option)
    {
        switch (Option)
        {
                case eQuickWithdraw:
                {
                   system("cls");
                   _ShowQuickWithdrawScreen();
                    _GoBackToATMMainMenu();
                    break;

                }
                case eNormalWithdraw:
                {
                    system("cls");
                    _ShowNormalWithdrawScreen();
                    _GoBackToATMMainMenu();
                    break;


                }
            

                case eDeposit:
                {
                     system("cls");
                    _ShowDepositScreen();
                    _GoBackToATMMainMenu();
                    break;


                }
                    

                case eCheckBalance:
                {

                    system("cls");
                    _ShowCheckBalanceScreen();
                    _GoBackToATMMainMenu();
                    break;
                }
                case eLogout:
                {
                    char Answer;

                    cout << "\nDo you want to save your session receipt? (y/n): ";
                    cin >> Answer;

                    if (toupper(Answer) == 'Y')
                    {
                        clsReceipt::SaveReceipt();
                    }

                    SessionTransactions.clear();

                    CurrentClient = clsATMClient::GetEmptyClientObject();

                    return;
                }
            
        }
    }

public:

    static void ShowATMMainMenu()
    {
        system("cls");

        _DrawScreenHeaderMain();
       _DrawScreenMainHeader();
        cout << setw(37) << left << "" << "\t========================================\n";
        cout << setw(37) << left  << "" << "\t\t[1] Quick Withdraw.\n";
        cout << setw(37) << left  << "" << "\t\t[2] Normal Withdraw.\n";
        cout << setw(37) << left  << "" << "\t\t[3] Deposit.\n";
        cout << setw(37) << left  << "" << "\t\t[4] Check Balance.\n";
        cout << setw(37) << left  << "" << "\t\t[5] Logout.\n";
        cout << setw(37) << left <<  "" << "\t========================================\n";
 
             _PerformATMMainMenuOption( (enATMMainMenuOptions)_ReadATMMainMenuOption() );
    }  
};     
