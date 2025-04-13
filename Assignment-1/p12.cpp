//Problem 11: Simple Banking System

#include <iostream>
#include <string>
using namespace std;

struct Account {
    string name;
    int accountNumber;
    float balance;
};

void deposit(Account &acc, float amount) {
    acc.balance += amount;
    cout << "Deposited: " << amount << ", New Balance: " << acc.balance << endl;
}

void withdraw(Account &acc, float amount) {
    if (amount <= acc.balance) {
        acc.balance -= amount;
        cout << "Withdrawn: " << amount << ", New Balance: " << acc.balance << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

int main() {
    Account acc;
    acc.balance = 0;
    cout << "Enter account holder's name and account number: ";
    cin >> acc.name >> acc.accountNumber;

    int choice;
    float amount;
    do {
        cout << "1. Deposit\n2. Withdraw\n3. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(acc, amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(acc, amount);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 3);
    return 0;
}