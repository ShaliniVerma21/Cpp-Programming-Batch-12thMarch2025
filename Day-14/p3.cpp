// Program 2: Encapsulation with Bank Account

#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    void showBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount b;
    b.deposit(5000);   // Cannot access balance directly
    b.showBalance();
    return 0;
}
