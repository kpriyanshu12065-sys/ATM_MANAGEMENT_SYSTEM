#include "Filemanager.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

const string USER_FILE = "users.txt";


// Save users
void saveUsers(const vector<ATM>& users)
{
    ofstream file(USER_FILE);

    if (!file)
    {
        cout << "Error: Unable to save user data.\n";
        return;
    }
    for (const ATM& user : users)
    {
        file << user.getAccountNo() << "|"
     << user.getName() << "|"
     << user.getPIN() << "|"
     << user.getBalance() << "|"
     << user.getMobile() << "\n";
    }

    file.close();
}


// Load users
void loadUsers(vector<ATM>& users)
{
    ifstream file(USER_FILE);

    if (!file)
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string accountStr;
        string name;
        string pinStr;
        string balanceStr;
        string mobile;

        getline(ss, accountStr, '|');
        getline(ss, name, '|');
        getline(ss, pinStr, '|');
        getline(ss, balanceStr, '|');
        getline(ss, mobile, '|');

        try
        {
            long long accountNo = stoll(accountStr);

            int pin = stoi(pinStr);

            double balance = stod(balanceStr);

            users.push_back(
                ATM(
                    accountNo,
                    name,
                    pin,
                    balance,
                    mobile
                )
            );
        }
        catch (...)
        {
            cout << "Invalid data found in users.txt\n";
        }
    }

    file.close();
}


// Find user
int findUser(
    const vector<ATM>& users,
    long long accountNo)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getAccountNo() == accountNo)
        {
            return i;
        }
    }

    return -1;
}