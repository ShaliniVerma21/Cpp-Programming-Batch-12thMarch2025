//17. Employee Directory with Salary Update

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>  // For formatted output

using namespace std;

// Abstract class to define the interface
class EmployeeInterface {
public:
    virtual void addEmployee() = 0;
    virtual void displayEmployees() = 0;
    virtual void updateSalary() = 0;
    virtual void deleteEmployee() = 0;
    virtual ~EmployeeInterface() {}
};

// Encapsulated Employee class
class Employee {
private:
    int id;
    string name;
    string position;
    double salary;

public:
    // Constructor
    Employee(int empId, string empName, string empPosition, double empSalary)
        : id(empId), name(empName), position(empPosition), salary(empSalary) {}

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    // Setter method
    void setSalary(double newSalary) { salary = newSalary; }

    // Display employee info
    void display() const {
        cout << "\n👤 ID: " << id
             << "\n📛 Name: " << name
             << "\n🏢 Position: " << position
             << "\n💰 Salary: ₹" << fixed << setprecision(2) << salary << "\n";
    }
};

// Inherited class from the interface
class EmployeeDirectory : public EmployeeInterface {
private:
    map<int, Employee> directory;  // STL map for fast lookup

public:
    // Add an employee
    void addEmployee() override {
        int id;
        string name, position;
        double salary;

        cout << "\nEnter Employee ID: ";
        cin >> id;
        cin.ignore();

        if (directory.find(id) != directory.end()) {
            cout << "❌ Employee ID already exists.\n";
            return;
        }

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Position: ";
        getline(cin, position);

        cout << "Enter Salary: ₹";
        cin >> salary;

        if (salary <= 0) {
            cout << "❌ Salary must be positive.\n";
            return;
        }

        Employee emp(id, name, position, salary);
        directory[id] = emp;

        cout << "✅ Employee added successfully.\n";
    }

    // Display all employees
    void displayEmployees() override {
        if (directory.empty()) {
            cout << "\n⚠️ No employee records found.\n";
            return;
        }

        cout << "\n========== 👨‍💼 Employee Directory ==========\n";
        for (auto& [id, emp] : directory) {
            emp.display();
        }
    }

    // Update salary of an employee
    void updateSalary() override {
        int id;
        double newSalary;

        cout << "\nEnter Employee ID to update salary: ";
        cin >> id;

        auto it = directory.find(id);
        if (it == directory.end()) {
            cout << "❌ Employee not found.\n";
            return;
        }

        cout << "Enter New Salary: ₹";
        cin >> newSalary;

        if (newSalary <= 0) {
            cout << "❌ Salary must be positive.\n";
            return;
        }

        it->second.setSalary(newSalary);
        cout << "✅ Salary updated successfully.\n";
    }

    // Delete an employee
    void deleteEmployee() override {
        int id;
        cout << "\nEnter Employee ID to delete: ";
        cin >> id;

        if (directory.erase(id)) {
            cout << "✅ Employee deleted successfully.\n";
        } else {
            cout << "❌ Employee ID not found.\n";
        }
    }
};

// Function to show menu
void showMenu() {
    cout << "\n=========== 🧾 MENU ===========\n";
    cout << "1. Add Employee\n";
    cout << "2. Display All Employees\n";
    cout << "3. Update Employee Salary\n";
    cout << "4. Delete Employee\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    EmployeeDirectory directory;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: directory.addEmployee(); break;
                case 2: directory.displayEmployees(); break;
                case 3: directory.updateSalary(); break;
                case 4: directory.deleteEmployee(); break;
                case 5: cout << "\n👋 Exiting Employee Directory. Goodbye!\n"; break;
                default: throw invalid_argument("❌ Invalid choice! Please select between 1-5.");
            }
        } catch (const exception& e) {
            cout << "\n[ERROR]: " << e.what() << "\n";
        }
    } while (choice != 5);

    return 0;
}
