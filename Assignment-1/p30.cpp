//4.Implement a Simple ATM

#include <iostream>
using namespace std;

int main() {
    int pin = 1234, enteredPin, choice;
    float balance = 1000.0, amount;

    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (enteredPin == pin) {
        do {
            cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Your balance is: $" << balance << endl;
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    balance += amount;
                    cout << "Deposited: $" << amount << endl;
                    break;
                case 3:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    if (amount <= balance) {
                        balance -= amount;
                        cout << "Withdrawn: $" << amount << endl;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Incorrect PIN." << endl;
    }
    return 0;
}