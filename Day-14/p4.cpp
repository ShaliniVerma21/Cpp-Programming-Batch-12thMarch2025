//Program 3: Encapsulation in Employee Class

#include <iostream>
using namespace std;

class Employee {
private:
    int empId;
    double salary;

public:
    void setDetails(int id, double sal) {
        empId = id;
        salary = sal;
    }

    void displayDetails() {
        cout << "Employee ID: " << empId << endl;
        cout << "Salary: ₹" << salary << endl;
    }
};

int main() {
    Employee e;
    e.setDetails(101, 45000.50);
    e.displayDetails();
    return 0;
}
