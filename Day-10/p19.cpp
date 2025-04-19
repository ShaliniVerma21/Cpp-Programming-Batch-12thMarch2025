//8. Expense Tracker

#include <iostream>
#include <vector>

class Expense {
public:
    std::string description;
    double amount;

    Expense(std::string desc, double amt) : description(desc), amount(amt) {}
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const Expense& expense) {
        expenses.push_back(expense);
    }

    void displayExpenses() const {
        for (const auto& expense : expenses) {
            std::cout << "Expense: " << expense.description << ", Amount: " << expense.amount << "\n";
        }
    }
};