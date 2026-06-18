#pragma once
#include <iostream>
#include "Screen.h"
#include "Global.h"

using namespace std;

class clsCheckBalanceScreen : protected clsScreen
{
public:

    static void ShowCheckBalanceScreen()
    {
        system("cls");

        _DrawScreenHeader("\tCheck Balance Screen");

        cout << "\nYour Balance is: "
            << CurrentClient.AccountBalance()
            << endl;
    }
};