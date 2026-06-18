#include <iostream>
#include "LoginScreen.h"

using namespace std;

int main()
{
    system("color 0B");

    while (true)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    return 0;
}