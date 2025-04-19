//6. Employee Class

#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(string n, double s) {
        name = n;
        salary = s;
    }

    void displayInfo() {
        cout << "Employee Name: " << name << ", Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", 75000);
    emp.displayInfo();
    return 0;
}