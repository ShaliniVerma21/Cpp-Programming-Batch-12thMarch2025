//7. Employee Salary Using Polymorphism

#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0; // abstraction
};

class FullTime : public Employee {
    double salary;
public:
    FullTime(double s) : salary(s) {}
    double calculateSalary() override {
        return salary;
    }
};

class PartTime : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTime(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() override {
        return hourlyRate * hours;
    }
};

int main() {
    Employee* e1 = new FullTime(50000);
    Employee* e2 = new PartTime(200, 100);

    cout << "Full-time salary: " << e1->calculateSalary() << endl;
    cout << "Part-time salary: " << e2->calculateSalary() << endl;

    delete e1;
    delete e2;
    return 0;
}
