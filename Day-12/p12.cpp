//Bank Transaction History

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For setting precision
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for transaction types
enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL
};

// Structure for a transaction
struct Transaction {
    TransactionType type; // Type of transaction
    double amount; // Amount of the transaction
    string date; // Date of the transaction

    // Constructor for Transaction
    Transaction(TransactionType t, double a, const string& d) 
        : type(t), amount(a), date(d) {}
};

// Base class for BankAccount
class BankAccount {
protected:
    string accountHolder; // Name of the account holder
    double balance; // Current balance
    vector<Transaction> transactions; // List of transactions

public:
    // Constructor for BankAccount
    BankAccount(const string& holder, double initialBalance) 
        : accountHolder(holder), balance(initialBalance) {}

    // Function to deposit money
    void deposit(double amount, const string& date) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        transactions.emplace_back(TransactionType::DEPOSIT, amount, date);
    }

    // Function to withdraw money
    void withdraw(double amount, const string& date) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds for withdrawal.");
        }
        balance -= amount;
        transactions.emplace_back(TransactionType::WITHDRAWAL, amount, date);
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    // Function to display transaction history
    void displayTransactionHistory() const {
        cout << "Transaction History:\n";
        for (const auto& transaction : transactions) {
            cout << (transaction.type == TransactionType::DEPOSIT ? "Deposit" : "Withdrawal")
                 << ": $" << fixed << setprecision(2) << transaction.amount 
                 << " on " << transaction.date << endl;
        }
    }

    // Virtual destructor
    virtual ~BankAccount() {}
};

// Derived class for SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Interest rate for the savings account

public:
    // Constructor for SavingsAccount
    SavingsAccount(const string& holder, double initialBalance, double rate) 
        : BankAccount(holder, initialBalance), interestRate(rate) {}

    // Function to apply interest to the account
    void applyInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest, "Interest Applied");
    }
};

int main() {
    // Create a SavingsAccount instance
    SavingsAccount myAccount("John Doe", 1000.00, 5.0); // Initial balance of $1000 with 5% interest

    // Display account details
    myAccount.displayAccountDetails();
    cout << endl;

    // Perform transactions
    try {
        myAccount.deposit(200.00, "2023-10-01"); // Deposit $200
        myAccount.withdraw(150.00, "2023-10-02"); // Withdraw $150
        myAccount.applyInterest(); // Apply interest

        // Display account details after transactions
        myAccount.displayAccountDetails();
        cout << endl;

        // Display transaction history
        myAccount.displayTransactionHistory();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}