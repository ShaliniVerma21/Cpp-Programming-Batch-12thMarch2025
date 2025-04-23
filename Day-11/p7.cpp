/*
Classes, Object & Functions : 

A class is a blueprint for creating objects. It encapsulates data and functions that operate on that data.

Members can include:
Data Members: Variables that hold the state of the object.
Member Functions: Functions that define the behavior of the object.


Access Specifiers : 

Access specifiers control the visibility of class members:
Public: Members are accessible from outside the class.
Private: Members are accessible only within the class.
Protected: Members are accessible within the class and by derived classes.
*/

#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    void honk() {
        cout << "Beep! Beep!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";
    myCar.honk();
    cout << "Car brand: " << myCar.brand << endl;
    return 0;
}