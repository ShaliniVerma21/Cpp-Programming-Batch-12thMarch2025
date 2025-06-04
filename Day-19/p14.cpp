//14. Tuition Fee Tracker

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract base class (Abstraction)
class TuitionInterface {
public:
    virtual void addStudent() = 0;
    virtual void viewStudents() = 0;
    virtual void updateFee() = 0;
    virtual void deleteStudent() = 0;
    virtual ~TuitionInterface() {}
};

// Student class (Encapsulation)
class Student {
protected:
    int id;
    string name;
    float totalFee;
    float paidFee;

public:
    // Constructor
    Student(int i, string n, float tf) : id(i), name(n), totalFee(tf), paidFee(0.0f) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    float getTotalFee() const { return totalFee; }
    float getPaidFee() const { return paidFee; }
    float getDue() const { return totalFee - paidFee; }

    // Setters
    void addPayment(float amount) {
        if (amount < 0) throw invalid_argument("Amount cannot be negative.");
        if (paidFee + amount > totalFee) throw overflow_error("Exceeds total fee.");
        paidFee += amount;
    }

    // Display details
    void display() const {
        cout << left << setw(6) << id
             << setw(20) << name
             << setw(12) << totalFee
             << setw(12) << paidFee
             << setw(12) << getDue() << "\n";
    }
};

// Tuition Manager class using Inheritance
class TuitionManager : public TuitionInterface {
private:
    map<int, Student> studentMap; // RollNo to Student

public:
    // Add student (Create)
    void addStudent() override {
        int id;
        string name;
        float fee;

        cout << "\nEnter Student ID: ";
        cin >> id;
        cin.ignore();

        if (studentMap.find(id) != studentMap.end()) {
            cout << "❌ Student with this ID already exists.\n";
            return;
        }

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Total Tuition Fee: ";
        cin >> fee;

        // Create and add student
        Student s(id, name, fee);
        studentMap[id] = s;
        cout << "✅ Student added successfully!\n";
    }

    // View all students (Read)
    void viewStudents() override {
        cout << "\n📋 Tuition Fee Tracker\n";
        cout << left << setw(6) << "ID" << setw(20) << "Name"
             << setw(12) << "Total Fee"
             << setw(12) << "Paid Fee"
             << setw(12) << "Due\n";
        cout << string(60, '-') << "\n";

        for (const auto& pair : studentMap) {
            pair.second.display();
        }
    }

    // Update payment (Update)
    void updateFee() override {
        int id;
        float amount;

        cout << "\nEnter Student ID to Update Payment: ";
        cin >> id;

        auto it = studentMap.find(id);
        if (it == studentMap.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        cout << "Enter Amount to Pay: ";
        cin >> amount;

        try {
            it->second.addPayment(amount);
            cout << "✅ Payment added successfully.\n";
        } catch (const exception& e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // Delete student (Delete)
    void deleteStudent() override {
        int id;
        cout << "\nEnter Student ID to Remove: ";
        cin >> id;

        if (studentMap.erase(id)) {
            cout << "✅ Student removed successfully.\n";
        } else {
            cout << "❌ Student not found.\n";
        }
    }
};

// Display menu
void showMenu() {
    cout << "\n========= 🎓 Tuition Fee Tracker =========\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Update Fee Payment\n";
    cout << "4. Remove Student\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

// Main Function
int main() {
    TuitionManager tm;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1: tm.addStudent(); break;
                case 2: tm.viewStudents(); break;
                case 3: tm.updateFee(); break;
                case 4: tm.deleteStudent(); break;
                case 5: cout << "\n👋 Exiting Tuition Fee Tracker...\n"; break;
                default: throw invalid_argument("❌ Invalid option. Try between 1-5.");
            }

        } catch (const exception& e) {
            cout << "\n[Error] " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
