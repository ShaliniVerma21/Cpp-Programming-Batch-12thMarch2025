/*
Benefits of Abstraction-->

1. Encapsulation: 
Abstraction often works hand-in-hand with encapsulation, allowing you to bundle data and methods that operate 
on that data within a single unit.

2. Improved Security: 
By hiding implementation details, abstraction can help protect sensitive data and reduce the risk of 
unintended interference.

Real-World Example -->

Consider a banking system where you have different types of accounts (e.g., Savings, Checking). 
You can create an abstract class BankAccount that defines common operations like deposit() and withdraw(), 
while each specific account type implements these operations differently.
*/

#include <iostream>
using namespace std;

// Abstract class
class BankAccount {
public:
    virtual void deposit(double amount) = 0; // Pure virtual function
    virtual void withdraw(double amount) = 0; // Pure virtual function
    virtual void displayBalance() = 0; // Pure virtual function
};

class SavingsAccount : public BankAccount {
private:
    double balance;
public:
    SavingsAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void displayBalance() override {
        cout << "Savings Account Balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double balance;
public:
    CheckingAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        balance -= amount; // Allow overdraft for simplicity
    }

    void displayBalance() override {
        cout << "Checking Account Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount* savings = new SavingsAccount();
    BankAccount* checking = new CheckingAccount();

    savings->deposit(1000);
    checking->deposit(500);

    savings->withdraw(200);
    checking->withdraw(600);

    savings->displayBalance(); // Output: Savings Account Balance: $800
    checking->displayBalance(); // Output: Checking Account Balance: -$100

    delete savings; // Clean up
    delete checking; // Clean up
    return 0;
}