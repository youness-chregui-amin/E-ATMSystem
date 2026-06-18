#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"
#include "StringLib.h"

using namespace std;

class clsATMClient : public clsPerson
{
private:

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };

    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;

    static clsATMClient _ConvertLineToClientObject(string Line,
        string Separator = "#//#")
    {
        vector<string> vData;

        vData = clsString::Split(Line, Separator);

        return clsATMClient(
            UpdateMode,
            vData[0],
            vData[1],
            vData[2],
            vData[3],
            stod(vData[4])
        );
    }

    static string _ConvertClientObjectToLine(clsATMClient Client,
        string Separator = "#//#")
    {
        string Record = "";

        Record += Client.AccountNumber() + Separator;
        Record += Client.PinCode() + Separator;
        Record += Client.Name() + Separator;
        Record += Client.Phone() + Separator;
        Record += to_string(Client.AccountBalance());

        return Record;
    }

    static vector<clsATMClient> _LoadClientsDataFromFile()
    {
        vector<clsATMClient> vClients;

        fstream File;
        File.open("Clients.txt", ios::in);

        if (File.is_open())
        {
            string Line;

            while (getline(File, Line))
            {
                vClients.push_back(
                    _ConvertLineToClientObject(Line));
            }

            File.close();
        }

        return vClients;
    }

public:

    clsATMClient(enMode Mode,
        string AccountNumber,
        string PinCode,
        string Name,
        string Phone,
        double AccountBalance)

        : clsPerson(Name, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    static clsATMClient GetEmptyClientObject()
    {
        return clsATMClient(
            EmptyMode,
            "",
            "",
            "",
            "",
            0
        );
    }

    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    string PinCode()
    {
        return _PinCode;
    }

    double AccountBalance()
    {
        return _AccountBalance;
    }

    static clsATMClient Find(string AccountNumber,
        string PinCode)
    {
        vector<clsATMClient> vClients =
            _LoadClientsDataFromFile();

        for (clsATMClient& Client : vClients)
        {
            if (Client.AccountNumber() == AccountNumber
                && Client.PinCode() == PinCode)
            {
                return Client;
            }
        }

        return GetEmptyClientObject();
    }

    bool Deposit(double Amount)
    {
        _AccountBalance += Amount;
        return Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
            return false;

        _AccountBalance -= Amount;

        return Save();
    }

    bool Save()
    {
        vector<clsATMClient> vClients =
            _LoadClientsDataFromFile();

        for (clsATMClient& C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C = *this;
                break;
            }
        }

        fstream File;
        File.open("Clients.txt", ios::out);

        if (!File.is_open())
            return false;

        for (clsATMClient& C : vClients)
        {
            File << _ConvertClientObjectToLine(C)
                << endl;
        }

        File.close();

        return true;
    }
};