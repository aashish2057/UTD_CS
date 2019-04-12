#ifndef EMPLOYEECLASS_H
#define EMPLOYEECLASS_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Bank
{
    private:
        int accountNum;
        string name;
        double balance;
        char AccountType;
    public:
        Bank();
        Bank(int, string, double);
        string withdraw(double);
        double deposit(double);
        

        void setAccountNum(int);
        void setName(string);
        void setBalance(double);
        void setAccountType(char);

        int getAccountNum(int) const;
        string getName(string) const;
        double getBalance(double) const;
        char getAccountType(char) const;
};

class Savings : public Bank
{
    private:
        float interest;
        int compoundtime;
    public:
        Savings();
        Savings(int, string, double);
        void setInterest(float);
        void setCompoundTime(int);
        void getInterest() const;
        void getCompoundTime() const;
        double addInterest(int, float);
};

class Checking : public Bank
{
    private:
        double minBalance;
        double monthlyFee;

    public:
        Checking();
        Checking(int, string, double);
        void setMinBal(double);
        void setMonthlyFee(double);
        double getMinBal() const;
        double getMonthlyFee() const;
};

#endif // EMPLOYEECLASS_H