//Personal Budget Planner

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for transaction types
enum class TransactionType {
    INCOME,
    EXPENSE
};

// Structure for a financial transaction
struct Transaction {
    string description; // Description of the transaction
    double amount; // Amount of the transaction
    TransactionType type; // Type of the transaction (income or expense)

    // Constructor for Transaction
    Transaction(string desc, double amt, TransactionType t)
        : description(desc), amount(amt), type(t) {}
};

// Base class for Budget
class Budget {
protected:
    vector<Transaction> transactions; // Vector to store transactions

public:
    // Function to add a transaction
    void addTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
    }

    // Function to calculate total income
    double calculateTotalIncome() const {
        double total = 0.0;
        for (const auto& transaction : transactions) {
            if (transaction.type == TransactionType::INCOME) {
                total += transaction.amount;
            }
        }
        return total;
    }

    // Function to calculate total expenses
    double calculateTotalExpenses() const {
        double total = 0.0;
        for (const auto& transaction : transactions) {
            if (transaction.type == TransactionType::EXPENSE) {
                total += transaction.amount;
            }
        }
        return total;
    }

    // Function to calculate net balance
    double calculateNetBalance() const {
        return calculateTotalIncome() - calculateTotalExpenses();
    }

    // Function to display all transactions
    void displayTransactions() const {
        cout << "Transactions:\n";
        for (const auto& transaction : transactions) {
            cout << (transaction.type == TransactionType::INCOME ? "Income: " : "Expense: ")
                 << transaction.description << " - $" << fixed << setprecision(2) << transaction.amount << endl;
        }
    }

    // Virtual destructor
    virtual ~Budget() {}
};

// Derived class for Personal Budget
class PersonalBudget : public Budget {
public:
    // Function to display budget summary
    void displayBudgetSummary() const {
        cout << "=== Budget Summary ===\n";
        cout << "Total Income: $" << fixed << setprecision(2) << calculateTotalIncome() << endl;
        cout << "Total Expenses: $" << fixed << setprecision(2) << calculateTotalExpenses() << endl;
        cout << "Net Balance: $" << fixed << setprecision(2) << calculateNetBalance() << endl;
    }
};

int main() {
    // Create an instance of PersonalBudget
    PersonalBudget myBudget;

    // Add transactions
    myBudget.addTransaction(Transaction("Salary", 3000.00, TransactionType::INCOME));
    myBudget.addTransaction(Transaction("Rent", 1200.00, TransactionType::EXPENSE));
    myBudget.addTransaction(Transaction("Groceries", 300.00, TransactionType::EXPENSE));
    myBudget.addTransaction(Transaction("Utilities", 150.00, TransactionType::EXPENSE));
    myBudget.addTransaction(Transaction("Freelance Work", 500.00, TransactionType::INCOME));

    // Display all transactions
    myBudget.displayTransactions();
    cout << endl;

    // Display budget summary
    myBudget.displayBudgetSummary();

    return 0;
}