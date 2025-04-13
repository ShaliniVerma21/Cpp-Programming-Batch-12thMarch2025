//10. complex real-world program using pointers that simulates a banking system

#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    string accountNumber;
    string accountHolder;
    double balance;

    Account(string accountNumber, string accountHolder, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Bank {
private:
    Account** accounts;
    int capacity;
    int size;

public:
    Bank(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        accounts = new Account*[capacity];
    }

    ~Bank() {
        for (int i = 0; i < size; i++) {
            delete accounts[i];
        }
        delete[] accounts;
    }

    void addAccount(Account* account) {
        if (size < capacity) {
            accounts[size] = account;
            size++;
            cout << "Account added successfully!" << endl;
        } else {
            cout << "Bank is full. Cannot add more accounts." << endl;
        }
    }

    void removeAccount(string accountNumber) {
        for (int i = 0; i < size; i++) {
            if (accounts[i]->accountNumber == accountNumber) {
                for (int j = i; j < size - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                size--;
                cout << "Account removed successfully!" << endl;
                return;
            }
        }
        cout << "Account not found in the bank." << endl;
    }

    void displayAllAccounts() {
        for (int i = 0; i < size; i++) {
            accounts[i]->displayAccountInfo();
            cout << endl;
        }
    }

    void searchAccount(string accountNumber) {
        for (int i = 0; i < size; i++) {
            if (accounts[i]->accountNumber == accountNumber) {
                accounts[i]->displayAccountInfo();
                return;
            }
        }
        cout << "Account not found in the bank." << endl;
    }

    void deposit(string accountNumber, double amount) {
        for (int i = 0; i < size; i++) {
            if (accounts[i]->accountNumber == accountNumber) {
                accounts[i]->balance += amount;
                cout << "Deposit successful!" << endl;
                return;
            }
        }
        cout << "Account not found in the bank." << endl;
    }

    void withdraw(string accountNumber, double amount) {
        for (int i = 0; i < size; i++) {
            if (accounts[i]->accountNumber == accountNumber) {
                if (accounts[i]->balance >= amount) {
                    accounts[i]->balance -= amount;
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Insufficient balance." << endl;
                }
                return;
            }
        }
        cout << "Account not found in the bank." << endl;
    }
};

int main() {
    Bank bank(10);

    while (true) {
        cout << "1. Add Account" << endl;
        cout << "2. Remove Account" << endl;
        cout << "3. Display All Accounts" << endl;
        cout << "4. Search Account" << endl;
        cout << "5. Deposit" << endl;
        cout << "6. Withdraw" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountNumber, accountHolder;
                double balance;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter account holder: ";
                cin >> accountHolder;
                cout << "Enter initial balance: ";
                cin >> balance;
                Account* account = new Account(accountNumber, accountHolder, balance);
                bank.addAccount(account);
                break;
            }
            case 2: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.removeAccount(accountNumber);
                break;
            }
            case 3:
                bank.displayAllAccounts();
                break;
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.searchAccount(accountNumber);
                break;
            }
            case 5: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> account Number;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 6: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}