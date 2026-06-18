#pragma once
#include <iostream>
#include "Screen.h"
#include "ATMClient.h"
#include "Global.h"
#include "ATMMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 0;

        string AccountNumber, PinCode;

        do
        {
            system("cls");
            _DrawScreenHeader("\tLogin Screen");

            if (LoginFailed)
            {
                FailedLoginCount++;

                cout << "\nInvalid Account Number / PinCode!";
                cout << "\nYou have " << (3 - FailedLoginCount)
                    << " trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are locked after 3 failed trials.\n\n";
                return false;
            }

            cout << "Enter Account Number > ";
            cin >> AccountNumber;

            cout << "Enter PinCode > ";
            cin >> PinCode;

            CurrentClient = clsATMClient::Find(AccountNumber, PinCode);

            LoginFailed = CurrentClient.IsEmpty();

        } while (LoginFailed);

        clsATMMainScreen::ShowATMMainMenu();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        return _Login();
    }
};