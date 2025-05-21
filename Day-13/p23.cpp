//9. Payment Gateway System (Polymorphism)

#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay(double amount) = 0; // abstraction
};

class CreditCard : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

class PayPal : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " using PayPal." << endl;
    }
};

int main() {
    Payment* p;
    CreditCard cc;
    PayPal pp;

    p = &cc;
    p->pay(100);

    p = &pp;
    p->pay(200);

    return 0;
}
