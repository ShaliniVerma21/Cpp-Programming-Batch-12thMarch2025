//5. Polymorphism in Bank Account Example

#include <iostream>
using namespace std;

class Account {
public:
    virtual void interestRate() {
        cout << "General account interest rate." << endl;
    }
};

class SavingsAccount : public Account {
public:
    void interestRate() override {
        cout << "Savings account interest rate: 5%" << endl;
    }
};

class CurrentAccount : public Account {
public:
    void interestRate() override {
        cout << "Current account interest rate: 3%" << endl;
    }
};

int main() {
    Account* acc1;
    SavingsAccount sa;
    CurrentAccount ca;

    acc1 = &sa;
    acc1->interestRate();

    acc1 = &ca;
    acc1->interestRate();

    return 0;
}
