/*

Encapsulation-->
Encapsulation is a fundamental concept in object-oriented programming (OOP) that binds together the data and
code (methods)into a single unit, like a capsule.
It helps to protect data from direct access — we use private variables and give access via public methods.

Think of a mobile phone:

You press a button to call (you don't know internal wiring).

The details (data) are hidden inside and accessed using buttons (methods).
That is Encapsulation.


Benefits of Encapsulation-->

Protects data (hides internal details)

Improves code security

Makes code easy to use and maintain


*/

#include <iostream>
using namespace std;

// Encapsulated class
class Student {
private:
    string name;
    int age;

public:
    // Setter method to set data (write)
    void setData(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }

    // Getter method to get data (read)
    void displayData() {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
    }
};

int main() {
    Student s1;

    // Set data using method
    s1.setData("Rahul", 20);

    // Get data using method
    s1.displayData();

    return 0;
}

/*
name and age are private → cannot be accessed directly.

setData() and displayData() are public → used to set and get data.

This is encapsulation — keeping data safe and controlling access.
*/