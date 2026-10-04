
#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:
    long long accountNo;
    string name;
    int pin;
    double balance;
    string mobile;

public:

    // Default constructor
    ATM();

    // Parameterized constructor
    ATM(
        long long accountNo,
        string name,
        int pin,
        double balance,
        string mobile
    );

    // Getter functions
    long long getAccountNo() const;
    string getName() const;
    int getPIN() const;
    double getBalance() const;
    string getMobile() const;

    // Setter functions
    void setPIN(int newPIN);
    void setMobile(string newMobile);

    // Banking operations
    bool deposit(double amount);
    bool withdraw(double amount);

    // Display
    void displayDetails() const;
};

#endif
