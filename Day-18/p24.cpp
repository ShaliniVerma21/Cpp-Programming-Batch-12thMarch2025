//Employee Payroll System with CRUD & STL Concepts

// Employee Payroll System using C++ STL and OOPs

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for formatted output
using namespace std;

// Employee class with name, id, and salary
class Employee {
public:
    int id;
    string name;
    float salary;

    Employee(int i, string n, float s) : id(i), name(n), salary(s) {}

    void display() const {
        cout << setw(5) << id << setw(15) << name << setw(10) << salary << endl;
    }
};

// Functor to filter employees with salary above a threshold
class SalaryAbove {
    float threshold;
public:
    SalaryAbove(float t) : threshold(t) {}
    bool operator()(const Employee& e) const {
        return e.salary > threshold;
    }
};

// Functor for sorting employees by salary (descending)
class SortBySalaryDesc {
public:
    bool operator()(const Employee& a, const Employee& b) {
        return a.salary > b.salary;
    }
};

// Function declarations
void addEmployee(vector<Employee>& empList);
void displayEmployees(const vector<Employee>& empList);
void updateSalary(vector<Employee>& empList);
void deleteEmployee(vector<Employee>& empList);
void filterBySalary(const vector<Employee>& empList);
void sortEmployees(vector<Employee>& empList);

int main() {
    vector<Employee> empList;
    int choice;

    do {
        cout << "\n======== Employee Payroll System ========\n";
        cout << "1. Add Employee\n2. Display All\n3. Update Salary\n";
        cout << "4. Delete Employee\n5. Filter Salary > Amount\n";
        cout << "6. Sort by Salary (Descending)\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addEmployee(empList); break;
            case 2: displayEmployees(empList); break;
            case 3: updateSalary(empList); break;
            case 4: deleteEmployee(empList); break;
            case 5: filterBySalary(empList); break;
            case 6: sortEmployees(empList); break;
            case 7: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 7);

    return 0;
}

// CRUD Operation: Add Employee
void addEmployee(vector<Employee>& empList) {
    int id;
    string name;
    float salary;
    cout << "Enter Employee ID, Name, and Salary: ";
    cin >> id >> name >> salary;

    // Check if ID already exists
    for (auto& e : empList) {
        if (e.id == id) {
            cout << "Employee ID already exists.\n";
            return;
        }
    }

    empList.push_back(Employee(id, name, salary));
    cout << "Employee added successfully.\n";
}

// Display all employees using iterator
void displayEmployees(const vector<Employee>& empList) {
    if (empList.empty()) {
        cout << "No employee records found.\n";
        return;
    }

    cout << "\nID   Name           Salary\n";
    cout << "-----------------------------\n";
    for (auto it = empList.begin(); it != empList.end(); ++it) {
        it->display();
    }
}

// Update salary of an employee
void updateSalary(vector<Employee>& empList) {
    int id;
    float newSalary;
    cout << "Enter Employee ID to update salary: ";
    cin >> id;

    for (auto& e : empList) {
        if (e.id == id) {
            cout << "Current Salary: " << e.salary << endl;
            cout << "Enter New Salary: ";
            cin >> newSalary;
            if (newSalary < 0) {
                cout << "Invalid salary input.\n";
                return;
            }
            e.salary = newSalary;
            cout << "Salary updated successfully.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

// Delete an employee by ID
void deleteEmployee(vector<Employee>& empList) {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    auto it = remove_if(empList.begin(), empList.end(), [id](Employee e) {
        return e.id == id;
    });

    if (it != empList.end()) {
        empList.erase(it, empList.end());
        cout << "Employee deleted successfully.\n";
    } else {
        cout << "Employee ID not found.\n";
    }
}

// Filter employees with salary > limit using Functor & for_each
void filterBySalary(const vector<Employee>& empList) {
    float limit;
    cout << "Enter salary limit: ";
    cin >> limit;

    cout << "\nEmployees earning more than Rs. " << limit << ":\n";
    cout << "ID   Name           Salary\n";
    cout << "-----------------------------\n";

    for_each(empList.begin(), empList.end(), [&](const Employee& e) {
        if (SalaryAbove(limit)(e)) e.display();
    });
}

// Sort employees by salary using custom Functor
void sortEmployees(vector<Employee>& empList) {
    if (empList.size() < 2) {
        cout << "Not enough records to sort.\n";
        return;
    }

    sort(empList.begin(), empList.end(), SortBySalaryDesc());
    cout << "Employees sorted by salary (High to Low).\n";
}
