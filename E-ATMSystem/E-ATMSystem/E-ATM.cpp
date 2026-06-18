#include <iostream>
#include "LoginScreen.h"

using namespace std;

vector<stTransaction> SessionTransactions;

int main()
{
    system("color 0B");

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }

    return 0;
}