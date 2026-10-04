#include <iostream>
#include <vector>

#include "ATM.h"
#include "Filemanager.h"
#include "Transaction.h"
#include "InputValidator.h"

using namespace std;

vector<ATM> users;

// Function declarations
void mainMenu();
void atmMenu(int index);

void createAccount();
void login();
void depositMoney(int index);
void withdrawMoney(int index);
void changePIN(int index);
void updateMobile(int index);

 void createAccount()
{
    cout << "\n========================================\n";
    cout << "             CREATE ACCOUNT\n";
    cout << "========================================\n";

    long long accountNo;
    while (true)
    {
        cout << "Enter Account Number: ";
        cin >> accountNo;
        if (findUser(users, accountNo) == -1)
        {
            break;
        }
        cout << "Account already exists.\n";
    }

    cin.ignore();
    string name;

    cout << "Enter Full Name: ";
    getline(cin, name);

    int pin = getPINInput(
        "Create 4-digit PIN: "
    );

    double initialBalance = getAmount(
        "Enter Initial Deposit: Rs. "
    );

    string mobile = getMobile();
    ATM newUser(
        accountNo,
        name,
        pin,
        initialBalance,
        mobile
    );
    users.push_back(newUser);
    saveUsers(users);
    addTransaction(
        accountNo,
        "ACCOUNT CREATED",
        initialBalance,
        initialBalance
    );
    cout << "\nAccount created successfully!\n";
}

void depositMoney(int index)
{
    double amount = getAmount(
        "\nEnter amount to deposit: Rs. "
    );
    if (users[index].deposit(amount))
    {
        saveUsers(users);
        addTransaction(
            users[index].getAccountNo(),
            "DEPOSIT",
            amount,
            users[index].getBalance()
        );
        cout << "\nDeposit successful!\n";
    }
}

void withdrawMoney(int index)
{
    double amount = getAmount(
        "\nEnter amount to withdraw: Rs. "
    );
    if (users[index].withdraw(amount))
    {
        saveUsers(users);
        addTransaction(
            users[index].getAccountNo(),
            "WITHDRAW",
            amount,
            users[index].getBalance()
        );
        cout << "\nPlease collect your cash.\n";
    }
    else
    {
        cout << "\nInsufficient balance or invalid amount.\n";
    }
}

void login()
{
    long long accountNo;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    int index = findUser(users, accountNo);

    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    int attempts = 3;

    while (attempts > 0)
    {
        int pin;
        cout << "Enter PIN: ";
        cin >> pin;
        if (pin == users[index].getPIN())
        {
            cout << "\nLogin successful!\n";
            atmMenu(index);
            return;
        }
        attempts--;
        cout << "Incorrect PIN.\n";
    }
    cout << "Too many incorrect attempts.\n";
}

void changePIN(int index)
{
    cout << "\n========================================\n";
    cout << "              CHANGE PIN\n";
    cout << "========================================\n";

    int oldPIN;

    cout << "Enter current PIN: ";
    cin >> oldPIN;

    // Verify old PIN
    if (oldPIN != users[index].getPIN())
    {
        cout << "\nIncorrect current PIN.\n";
        return;
    }

    int newPIN = getPINInput(
        "Enter new 4-digit PIN: "
    );

    users[index].setPIN(newPIN);
    saveUsers(users);
    cout << "\nPIN changed successfully!\n";
}

void updateMobile(int index)
{
    cout << "\n========================================\n";
    cout << "          UPDATE MOBILE NUMBER\n";
    cout << "========================================\n";

    string newMobile;
    newMobile = getMobile();
    users[index].setMobile(newMobile);
    saveUsers(users);
    cout << "\nMobile number updated successfully!\n";
}

void atmMenu(int index)
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "             ATM MENU\n";
        cout << "========================================\n";
        cout << "1. Check Balance\n";
        cout << "2. Cash Withdraw\n";
        cout << "3. Deposit Money\n";
        cout << "4. Show User Details\n";
        cout << "5. Update Mobile Number\n";
        cout << "6. Change PIN\n";
        cout << "7. Mini Statement\n";
        cout << "8. Logout\n";
        cout << "========================================\n";

        choice = getInteger("Enter your choice: ");

        switch (choice)
        {
            case 1:
                cout << "\nCurrent Balance: Rs. "
                     << users[index].getBalance()
                     << endl;
                break;

            case 2:
                withdrawMoney(index);
                break;

            case 3:
                depositMoney(index);
                break;

            case 4:
                users[index].displayDetails();
                break;

            case 5:
                updateMobile(index);
                break;

            case 6:
                changePIN(index);
                break;

            case 7:
                miniStatement(
                    users[index].getAccountNo()
                );
                break;

            case 8:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 8);
}

void mainMenu()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "          **** WELCOME TO ATM ****\n";
        cout << "========================================\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "========================================\n";

        choice = getInteger("Enter your choice: ");
        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                cout << "\nThank you for using our ATM.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);
}

int main()
{
    loadUsers(users);

    mainMenu();

    return 0;
}