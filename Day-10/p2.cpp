//2. Bank Account Class

#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum) {
        accountNumber = accNum;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
        }
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount("123456789");
    myAccount.deposit(500);
    myAccount.withdraw(200);
    myAccount.displayBalance();
    return 0;
}