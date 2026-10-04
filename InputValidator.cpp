#include "InputValidator.h"

#include <iostream>
#include <limits>
#include <cctype>

using namespace std;


// Clear invalid input
void clearInput()
{
    cin.clear();

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );
}


// Get integer
int getInteger(string message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";

        clearInput();
    }
}


// Get amount
double getAmount(string message)
{
    double amount;

    while (true)
    {
        cout << message;

        if (cin >> amount && amount > 0)
        {
            return amount;
        }

        cout << "Please enter a valid positive amount.\n";

        clearInput();
    }
}


// Get mobile number
string getMobile()
{
    string mobile;

    while (true)
    {
        cout << "Enter Mobile Number: ";

        cin >> mobile;

        if (mobile.length() == 10)
        {
            bool valid = true;

            for (char c : mobile)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                return mobile;
            }
        }

        cout << "Mobile number must contain exactly 10 digits.\n";
    }
}


// Get PIN
int getPINInput(string message)
{
    int pin;

    while (true)
    {
        cout << message;

        if (cin >> pin &&
            pin >= 1000 &&
            pin <= 9999)
        {
            return pin;
        }

        cout << "PIN must contain exactly 4 digits.\n";

        clearInput();
    }
}