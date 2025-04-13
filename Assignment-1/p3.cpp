//Problem 2: Customer Management System

#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int age;
    string email;
};

void displayCustomer(Customer c) {
    cout << "Name: " << c.name << ", Age: " << c.age << ", Email: " << c.email << endl;
}

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    Customer customers[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name, age, and email: ";
        cin >> customers[i].name >> customers[i].age >> customers[i].email;
    }
    cout << "Customer Details:\n";
    for (int i = 0; i < n; i++) {
        displayCustomer(customers[i]);
    }
    return 0;
}