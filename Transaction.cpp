#include "Transaction.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

const string TRANSACTION_FILE = "transactions.txt";


// Get current date and time
string getDateTime()
{
    time_t now = time(nullptr);

    tm *localTime = localtime(&now);

    stringstream ss;

    ss << setfill('0')
       << setw(2) << localTime->tm_mday << "/"
       << setw(2) << localTime->tm_mon + 1 << "/"
       << localTime->tm_year + 1900
       << " "
       << setw(2) << localTime->tm_hour << ":"
       << setw(2) << localTime->tm_min << ":"
       << setw(2) << localTime->tm_sec;

    return ss.str();
}


// Add transaction
void addTransaction(
    long long accountNo,
    string type,
    double amount,
    double balance)
{
    ofstream file(
        TRANSACTION_FILE,
        ios::app
    );

    if (!file)
    {
        cout << "Unable to save transaction.\n";
        return;
    }

    file << accountNo << "|"
         << getDateTime() << "|"
         << type << "|"
         << fixed << setprecision(2)
         << amount << "|"
         << balance
         << endl;

    file.close();
}


// Display mini statement
void miniStatement(long long accountNo)
{
    ifstream file(TRANSACTION_FILE);

    if (!file)
    {
        cout << "\nNo transaction history available.\n";
        return;
    }

    string line;

    cout << "\n==============================================================\n";
    cout << "                     MINI STATEMENT\n";
    cout << "==============================================================\n";

    cout << left
         << setw(20) << "Date"
         << setw(22) << "Transaction"
         << setw(12) << "Amount"
         << setw(12) << "Balance"
         << endl;

    cout << "--------------------------------------------------------------\n";

    bool found = false;

    while (getline(file, line))
    {
        stringstream ss(line);

        string acc;
        string date;
        string type;
        string amount;
        string balance;

        getline(ss, acc, '|');
        getline(ss, date, '|');
        getline(ss, type, '|');
        getline(ss, amount, '|');
        getline(ss, balance, '|');

        if (stoll(acc) == accountNo)
        {
            found = true;

            cout << left
                 << setw(20) << date
                 << setw(22) << type
                 << setw(12) << amount
                 << setw(12) << balance
                 << endl;
        }
    }

    if (!found)
    {
        cout << "No transactions found.\n";
    }

    cout << "==============================================================\n";

    file.close();
}