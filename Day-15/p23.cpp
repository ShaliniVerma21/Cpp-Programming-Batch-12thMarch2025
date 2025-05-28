/*
1. Simple Banking System

This program simulates a basic banking system where users can create accounts, deposit money, withdraw money, 
and check their balance.    
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name) : accountHolder(name), balance(0) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        }
    }

    void checkBalance() const {
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    string name;
    int choice;

    cout << "Enter account holder's name: ";
    getline(cin, name);
    accounts.emplace_back(name);

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nChoose an option: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accounts[0].deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                accounts[0].withdraw(amount);
                break;
            case 3:
                accounts[0].checkBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}