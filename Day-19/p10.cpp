//10.Loan EMI Calculator & Billing System with Tax Calculation

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract class for EMI calculation
class EMIBase {
public:
    virtual double calculateEMI(double principal, double rate, int time) = 0;
    virtual ~EMIBase() {}
};

// Class for Loan EMI Calculation
class LoanEMICalculator : public EMIBase {
public:
    double calculateEMI(double principal, double rate, int time) override {
        double monthlyRate = rate / (12 * 100);
        int months = time * 12;
        double emi = (principal * monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);
        return emi;
    }
};

// Customer class with encapsulation
class Customer {
private:
    int id;
    string name;
    double loanAmount;
    double interestRate;
    int loanPeriod;
    double taxRate;
    double emiAmount;
    double totalPayment;

public:
    Customer() {}

    Customer(int id, string name, double loan, double rate, int period, double tax) {
        this->id = id;
        this->name = name;
        loanAmount = loan;
        interestRate = rate;
        loanPeriod = period;
        taxRate = tax;
    }

    void computeBilling(EMIBase* emiCalc) {
        emiAmount = emiCalc->calculateEMI(loanAmount, interestRate, loanPeriod);
        totalPayment = emiAmount * 12 * loanPeriod;
        totalPayment += totalPayment * (taxRate / 100); // Tax addition
    }

    void displayBill() const {
        cout << "\n---------------------------------------------------\n";
        cout << "Customer ID     : " << id << "\n";
        cout << "Customer Name   : " << name << "\n";
        cout << "Loan Amount     : ₹" << loanAmount << "\n";
        cout << "Interest Rate   : " << interestRate << "%\n";
        cout << "Loan Period     : " << loanPeriod << " years\n";
        cout << "Monthly EMI     : ₹" << fixed << setprecision(2) << emiAmount << "\n";
        cout << "Tax Rate        : " << taxRate << "%\n";
        cout << "Total Payment   : ₹" << fixed << setprecision(2) << totalPayment << "\n";
        cout << "---------------------------------------------------\n";
    }

    int getId() const { return id; }
};

// Manager class to handle CRUD operations
class BillingSystem {
private:
    map<int, Customer> customers;
    LoanEMICalculator emiCalculator;

public:
    void addCustomer() {
        int id;
        string name;
        double loan, rate, tax;
        int period;

        cout << "\nEnter Customer ID: ";
        cin >> id;
        if (customers.find(id) != customers.end()) {
            cout << "❌ Customer with ID already exists.\n";
            return;
        }

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Loan Amount: ₹";
        cin >> loan;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        cout << "Enter Loan Period (in years): ";
        cin >> period;
        cout << "Enter Tax Rate (%): ";
        cin >> tax;

        try {
            if (loan < 0 || rate < 0 || period <= 0 || tax < 0)
                throw invalid_argument("❌ Invalid input values!");

            Customer cust(id, name, loan, rate, period, tax);
            cust.computeBilling(&emiCalculator);
            customers[id] = cust;
            cout << "✅ Customer added successfully!\n";

        } catch (exception& e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    void viewCustomer() {
        if (customers.empty()) {
            cout << "\n🚫 No customer records available.\n";
            return;
        }

        int id;
        cout << "\nEnter Customer ID to view bill: ";
        cin >> id;

        auto it = customers.find(id);
        if (it != customers.end()) {
            it->second.displayBill();
        } else {
            cout << "❌ Customer not found.\n";
        }
    }

    void viewAllCustomers() {
        if (customers.empty()) {
            cout << "\n🚫 No customer records available.\n";
            return;
        }

        for (const auto& pair : customers) {
            pair.second.displayBill();
        }
    }

    void deleteCustomer() {
        int id;
        cout << "\nEnter Customer ID to delete: ";
        cin >> id;

        if (customers.erase(id)) {
            cout << "✅ Customer deleted successfully.\n";
        } else {
            cout << "❌ Customer not found.\n";
        }
    }
};

// Display Menu
void displayMenu() {
    cout << "\n========== 💰 Loan EMI & Billing Menu ==========\n";
    cout << "1. Add Customer Loan Detail\n";
    cout << "2. View Customer Bill\n";
    cout << "3. View All Customer Bills\n";
    cout << "4. Delete Customer Record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main driver function
int main() {
    BillingSystem system;
    int choice;

    do {
        try {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1: system.addCustomer(); break;
                case 2: system.viewCustomer(); break;
                case 3: system.viewAllCustomers(); break;
                case 4: system.deleteCustomer(); break;
                case 5: cout << "\n👋 Exiting Loan Billing System. Thank you!\n"; break;
                default: throw invalid_argument("❌ Invalid choice! Enter 1-5.");
            }
        } catch (exception& e) {
            cout << "⚠️ Exception: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
