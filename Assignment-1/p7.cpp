//Problem 6: Employee Details Management

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    float salary;
};

void displayEmployee(Employee emp) {
    cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee employees[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter employee ID, name, and salary: ";
        cin >> employees[i].id >> employees[i].name >> employees[i].salary;
    }
    cout << "Employee Details:\n";
    for (int i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }
    return 0;
}