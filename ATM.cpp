#include "ATM.h"

ATM::ATM()
{
    accountNo = 0;
    name = "";
    pin = 0;
    balance = 0;
    mobile = "";
}

ATM::ATM(
    long long accountNo,
    string name,
    int pin,
    double balance,
    string mobile
)
{
    this->accountNo = accountNo;
    this->name = name;
    this->pin = pin;
    this->balance = balance;
    this->mobile = mobile;
}

long long ATM::getAccountNo() const
{
    return accountNo;
}

string ATM::getName() const
{
    return name;
}

int ATM::getPIN() const
{
    return pin;
}

double ATM::getBalance() const
{
    return balance;
}

string ATM::getMobile() const
{
    return mobile;
}

void ATM::setPIN(int newPIN)
{
    pin = newPIN;
}

void ATM::setMobile(string newMobile)
{
    mobile = newMobile;
}

bool ATM::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;

    return true;
}

bool ATM::withdraw(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}

void ATM::displayDetails() const
{
    cout << "\n========================================\n";
    cout << "             USER DETAILS\n";
    cout << "========================================\n";

    cout << "Account Number : " << accountNo << endl;
    cout << "Name           : " << name << endl;
    cout << "Mobile Number  : " << mobile << endl;
    cout << "Balance        : Rs. " << balance << endl;
}