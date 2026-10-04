# ATM Management System

A console-based **ATM Management System** developed in **C++** as a Capstone Project. The project demonstrates object-oriented programming, file handling, input validation, account management, and basic banking transactions.

## Project Overview

The ATM Management System provides a simple simulation of ATM operations. Users can create accounts, log in using their account credentials, check their account details, deposit money, withdraw money, change their PIN, and update their mobile number.

The system stores user and transaction information using text files, allowing data to persist between program executions.

## Features

- Create a new ATM account
- Unique account number validation
- 4-digit PIN authentication
- User login
- Check account details
- Deposit money
- Withdraw money
- Balance validation during withdrawal
- Change PIN
- Update mobile number
- Input validation
- Persistent storage using text files
- Transaction record management

## Technologies Used

- **Programming Language:** C++
- **Concepts:** Object-Oriented Programming, File Handling, Data Validation
- **Data Storage:** Text files
- **Development Environment:** Visual Studio Code

## Project Structure

```text
ATM_MANAGEMENT_SYSTEM/
│
├── ATM.h
├── ATM.cpp
│
├── Filemanager.h
├── Filemanager.cpp
│
├── InputValidator.h
├── InputValidator.cpp
│
├── Transaction.h
├── Transaction.cpp
│
├── main.cpp
│
├── users.txt
├── transactions.txt
│
└── README.md
```

## Description of Important Files

### `main.cpp`

Contains the main program logic and menu-driven interface. It handles account creation, login, deposits, withdrawals, PIN changes, and other user operations.

### `ATM.h` / `ATM.cpp`

Defines and implements the `ATM` class. It manages account information such as:

- Account number
- Name
- PIN
- Balance
- Mobile number

It also provides functions for deposit, withdrawal, and displaying account details.

### `Filemanager.h` / `Filemanager.cpp`

Handles reading and writing user information to `users.txt`. This provides persistent storage for account data.

### `InputValidator.h` / `InputValidator.cpp`

Provides input validation functions to ensure that user-entered data follows the required format.

### `Transaction.h` / `Transaction.cpp`

Handles transaction-related information and maintains transaction records.

### `users.txt`

Stores user account information used by the application.

### `transactions.txt`

Stores transaction-related records.

## How to Compile

Make sure a C++ compiler such as `g++` is installed.

Compile the project using:

```bash
g++ main.cpp ATM.cpp Filemanager.cpp InputValidator.cpp Transaction.cpp -o atm
```

## How to Run

After successful compilation, run:

```bash
./atm
```

The program will display the ATM menu in the terminal.

## Basic Working Flow

```text
Start Program
      ↓
Main Menu
      ↓
Create Account / Login
      ↓
PIN Authentication
      ↓
ATM Operations
      ├── Check Account Details
      ├── Deposit
      ├── Withdraw
      ├── Change PIN
      └── Update Mobile Number
      ↓
Save Data
      ↓
Exit
```

## Data Persistence

The project uses text files to store information:

- `users.txt` → stores account information
- `transactions.txt` → stores transaction records

This allows information to remain available after the program is closed and started again.

## Project Objective

The objective of this project is to develop a simple ATM simulation while applying C++ programming concepts such as:

- Classes and Objects
- Encapsulation
- Constructors
- Member Functions
- File Handling
- Vectors
- Input Validation
- Menu-driven Programming

## Future Improvements

Possible future enhancements include:

- Database integration
- Password/PIN encryption
- Improved transaction history
- Multiple account types
- Administrator panel
- GUI-based interface
- Enhanced security mechanisms

## Author

**Priyanshu**

B.Tech Computer Science and Engineering

Siksha O Anusandhan University, Bhubaneswar
