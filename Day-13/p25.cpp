#include <iostream>
using namespace std;

// Abstract class - ATM interface (Abstraction)
class ATM {
public:
    virtual void insertCard() = 0;
    virtual void enterPIN() = 0;
    virtual void withdrawCash(double amount) = 0;
    virtual void checkBalance() = 0;
    virtual void depositMoney(double amount) = 0;
    virtual ~ATM() {} // Virtual destructor
};

// Concrete class - Bank ATM
class SBIATM : public ATM {
private:
    double balance;
    int pin;

public:
    SBIATM() {
        balance = 5000.0;
        pin = 1234;  // Dummy PIN
    }

    void insertCard() override {
        cout << "Card inserted successfully.\n";
    }

    void enterPIN() override {
        int enteredPIN;
        cout << "Enter your PIN: ";
        cin >> enteredPIN;
        if (enteredPIN == pin) {
            cout << "PIN verified successfully.\n";
        } else {
            cout << "Incorrect PIN. Try again.\n";
        }
    }

    void withdrawCash(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Please collect your cash: ₹" << amount << endl;
            cout << "Remaining Balance: ₹" << balance << endl;
        }
    }

    void checkBalance() override {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void depositMoney(double amount) override {
        balance += amount;
        cout << "Amount ₹" << amount << " deposited successfully.\n";
        cout << "New Balance: ₹" << balance << endl;
    }
};

int main() {
    // User accesses ATM interface only
    ATM* atm = new SBIATM();

    atm->insertCard();
    atm->enterPIN();
    atm->checkBalance();
    atm->withdrawCash(2000);
    atm->depositMoney(1500);
    atm->checkBalance();

    delete atm;
    return 0;
}
