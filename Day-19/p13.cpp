//13. Bank Account System

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract Base Class (Abstraction)
class BankInterface {
public:
    virtual void createAccount() = 0;
    virtual void viewAllAccounts() = 0;
    virtual void depositAmount() = 0;
    virtual void withdrawAmount() = 0;
    virtual void deleteAccount() = 0;
    virtual ~BankInterface() {}
};

// BankAccount Class (Encapsulation)
class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, string name, double initialBalance)
        : accountNumber(accNum), holderName(name), balance(initialBalance) {}

    // Getters
    int getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Amount must be positive.");
        balance += amount;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Amount must be positive.");
        if (amount > balance)
            throw runtime_error("Insufficient balance.");
        balance -= amount;
    }

    // Display account details
    void display() const {
        cout << left << setw(10) << accountNumber
             << setw(20) << holderName
             << setw(15) << fixed << setprecision(2) << balance << "\n";
    }
};

// Derived class using inheritance
class BankSystem : public BankInterface {
private:
    map<int, BankAccount> accounts; // Using STL map for CRUD

public:
    // Create account
    void createAccount() override {
        int accNum;
        string name;
        double initialBalance;

        cout << "\nEnter Account Number: ";
        cin >> accNum;

        if (accounts.find(accNum) != accounts.end()) {
            cout << "❌ Account already exists!\n";
            return;
        }

        cin.ignore(); // flush newline
        cout << "Enter Account Holder Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        // Creating account
        BankAccount acc(accNum, name, initialBalance);
        accounts[accNum] = acc;

        cout << "✅ Account created successfully!\n";
    }

    // View all accounts
    void viewAllAccounts() override {
        if (accounts.empty()) {
            cout << "\n📂 No accounts to display.\n";
            return;
        }

        cout << "\n📄 List of Bank Accounts:\n";
        cout << left << setw(10) << "Acc No"
             << setw(20) << "Holder Name"
             << setw(15) << "Balance\n";
        cout << string(45, '-') << "\n";

        for (const auto& acc : accounts) {
            acc.second.display();
        }
    }

    // Deposit amount
    void depositAmount() override {
        int accNum;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNum;

        auto it = accounts.find(accNum);
        if (it == accounts.end()) {
            cout << "❌ Account not found!\n";
            return;
        }

        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        try {
            it->second.deposit(amount);
            cout << "✅ Deposit successful!\n";
        } catch (exception &e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // Withdraw amount
    void withdrawAmount() override {
        int accNum;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNum;

        auto it = accounts.find(accNum);
        if (it == accounts.end()) {
            cout << "❌ Account not found!\n";
            return;
        }

        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        try {
            it->second.withdraw(amount);
            cout << "✅ Withdrawal successful!\n";
        } catch (exception &e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // Delete account
    void deleteAccount() override {
        int accNum;
        cout << "\nEnter Account Number to Delete: ";
        cin >> accNum;

        if (accounts.erase(accNum)) {
            cout << "✅ Account deleted successfully!\n";
        } else {
            cout << "❌ Account not found!\n";
        }
    }
};

// Show menu to user
void showMenu() {
    cout << "\n========= 🏦 Bank Account Management =========\n";
    cout << "1. Create Account\n";
    cout << "2. View All Accounts\n";
    cout << "3. Deposit Money\n";
    cout << "4. Withdraw Money\n";
    cout << "5. Delete Account\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    BankSystem bank;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1: bank.createAccount(); break;
                case 2: bank.viewAllAccounts(); break;
                case 3: bank.depositAmount(); break;
                case 4: bank.withdrawAmount(); break;
                case 5: bank.deleteAccount(); break;
                case 6: cout << "\n👋 Thank you for using the Bank System!\n"; break;
                default: throw invalid_argument("❌ Invalid option! Please choose 1-6.");
            }

        } catch (exception &e) {
            cout << "\n⚠️ Exception: " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}
