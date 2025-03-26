//2. Simple ATM Withdrawal
#include <iostream>

int main() {
    double balance = 1000.0; // Initial balance
    double withdrawal;

    std::cout << "Welcome to the ATM!" << std::endl;

    while (true) {
        std::cout << "Current balance: $" << balance << std::endl;
        std::cout << "Enter amount to withdraw (or -1 to exit): ";
        std::cin >> withdrawal;

        if (withdrawal == -1) {
            std::cout << "Thank you for using the ATM!" << std::endl;
            break; // Exit the loop
        } else if (withdrawal > balance) {
            std::cout << "Insufficient funds!" << std::endl;
        } else {
            balance -= withdrawal;
            std::cout << "You have withdrawn: $" << withdrawal << std::endl;
        }
    }

    return 0;
}