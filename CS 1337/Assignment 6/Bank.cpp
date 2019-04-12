#include "Bank.h"

Bank::Bank()
{
    accountNum = 9999;
    name = "";
    balance = 0.0;
}

Bank::Bank(int aNum, string n, double bal)
{
    accountNum = aNum;
    name = n;
    balance = bal;
}

string withdraw(double remove, double &bal)
{
    string message;
    if((bal - remove) < 0)
    {
        message = "Insufficent Funds";
    }
    else
    {
        bal -= remove;
        message = to_string(bal);
    }
   return message; 
}

double deposit(double &bal, double add)
{
    bal += add;
    return bal;
}

void Bank::setAccountNum(int aNum)
{
    accountNum = aNum;
}

void Bank::setName(string n)
{
    name = n;
}

void Bank::setBalance(double bal)
{
    balance = bal;
}

void Bank::setAccountType(char type)
{
    AccountType = type;
}

int Bank::getAccountNum(int aNum) const
{
    return accountNum;
}

string Bank::getName(string n) const
{
    return name;
}

double Bank::getBalance(double bal) const
{
    return balance;
}

char Bank::getAccountType(char type) const
{
    return AccountType;
}

