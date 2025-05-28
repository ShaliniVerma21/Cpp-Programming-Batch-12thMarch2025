//4. Encapsulation

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance; // Private member

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(100);
    cout << "Balance: " << account.getBalance() << endl; // Accessing private member through public method
    return 0;
}