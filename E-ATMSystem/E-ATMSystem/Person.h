#pragma once
#include <string>
using namespace std;

class clsPerson
{
private:
    string _Name;
    string _Phone;

public:

    clsPerson(string Name = "", string Phone = "")
    {
        _Name = Name;
        _Phone = Phone;
    }

    string Name()
    {
        return _Name;
    }

    void SetName(string Name)
    {
        _Name = Name;
    }

    string Phone()
    {
        return _Phone;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
};