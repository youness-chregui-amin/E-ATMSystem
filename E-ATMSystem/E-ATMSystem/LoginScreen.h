#pragma once
#pragma once
#include <iostream>
#include "Screen.h"
#include "ATMClient.h"
#include "Global.h"
#include "ATMMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
public:

    static void ShowLoginScreen()
    {
        string AccountNumber, PinCode;

        bool LoginFailed = false;

        do
        {
            system("cls");

            _DrawScreenHeader("\tLogin Screen");

            if (LoginFailed)
            {
                cout << "\nInvalid Account Number / PinCode!\n\n";
            }

            cout << "Enter Account Number > ";
            cin >> AccountNumber;

            cout << "Enter PinCode > ";
            cin >> PinCode;

            CurrentClient =
                clsATMClient::Find(AccountNumber, PinCode);

            LoginFailed = CurrentClient.IsEmpty();

        } while (LoginFailed);

        clsATMMainScreen::ShowATMMainMenu();
    }
};