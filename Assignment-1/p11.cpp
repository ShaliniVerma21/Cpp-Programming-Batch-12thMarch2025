//Problem 10: Personal Expense Tracker

#include <iostream>
#include <string>
using namespace std;

struct Expense {
    string description;
    float amount;
};

void displayExpenses(Expense expenses[], int count) {
    float total = 0;
    cout << "Description\tAmount\n";
    for (int i = 0; i < count; i++) {
        cout << expenses[i].description << "\t\t" << expenses[i].amount << endl;
        total += expenses[i].amount;
    }
    cout << "Total Expenses: " << total << endl;
}

int main() {
    int n;
    cout << "Enter number of expenses: ";
    cin >> n;
    Expense expenses[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter expense description and amount: ";
        cin >> expenses[i].description >> expenses[i].amount;
    }
    displayExpenses(expenses, n);
    return 0;
}