#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Global.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n";
        cout << setw(35) << left << "" << "=========================================\n";
        cout << setw(35) << left << "" << "            " << Title << "\n";

        if (!SubTitle.empty())
            cout << setw(35) << left << "" << "            " << SubTitle << "\n";

        cout << setw(35) << left << "" << "=========================================\n\n";

        if (!CurrentClient.IsEmpty())
        {
            cout << setw(35) << left << "" << "Client  : " << CurrentClient.Name() << "\n";
            cout << setw(35) << left << "" << "Account : " << CurrentClient.AccountNumber() << "\n";
            cout << setw(35) << left << "" << "Balance : $" << fixed << setprecision(2)
                << CurrentClient.AccountBalance() << "\n";
        }

        cout << setw(35) << left << "" << "Date    : " << _GetCurrentDateTime() << "\n";
        cout << setw(35) << left << "" << "-----------------------------------------\n\n";
    }
    static void _DrawScreenMainHeader()
    {
       

        cout << "\t\t\t\t\t\tClient: " << CurrentClient.Name() << "\n";
        cout << "\t\t\t\t\t\tAccount Number: " << CurrentClient.AccountNumber() << "\n";
        cout << "\t\t\t\t\t\tDate: " << _GetCurrentDateTime() << "\n\n";
    }
    static string _GetCurrentDateTime()
    {
        time_t t = time(nullptr);
        tm now;
        localtime_s(&now, &t);

        string DateTime =
            to_string(now.tm_mday) + "/" +
            to_string(now.tm_mon + 1) + "/" +
            to_string(now.tm_year + 1900) + " - " +
            to_string(now.tm_hour) + ":" +
            to_string(now.tm_min) + ":" +
            to_string(now.tm_sec);

        return DateTime;
    }
    static void _DrawScreenHeaderMain()
    {
        cout << "\t\t\t\t\t______________________________________\n";

        cout << R"(

                               __       _   _____        __           _                 
                              /__\     /_\ /__   \/\/\  / _\_   _ ___| |_ ___ _ __ ___  
                             /_\_____ //_\\  / /\/    \ \ \| | | / __| __/ _ \ '_ ` _ \ 
                            //_|_____/  _  \/ / / /\/\ \_\ \ |_| \__ \ ||  __/ | | | | |
                            \__/     \_/ \_/\/  \/    \/\__/\__, |___/\__\___|_| |_| |_|
                                                            |___/                       

)";

        cout << "\t\t\t\t\t______________________________________\n\n";
    }

    static void _GoBackMessage()
    {
        cout << "\n\nPress any key to go back...";
        system("pause>0");
    }
};