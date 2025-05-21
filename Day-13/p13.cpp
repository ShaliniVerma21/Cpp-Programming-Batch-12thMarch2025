//4. Abstraction

#include <iostream>
using namespace std;

class ATM {
public:
    virtual void withdraw(float amount) = 0;  // Pure virtual function
    virtual void deposit(float amount) = 0;
};

class BankATM : public ATM {
private:
    float balance;
public:
    BankATM() { balance = 1000; }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\nBalance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void deposit(float amount) override {
        balance += amount;
        cout << "Deposited: " << amount << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankATM obj;
    obj.deposit(500);
    obj.withdraw(300);
    return 0;
}
