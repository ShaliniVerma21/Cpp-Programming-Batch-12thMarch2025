//Example 3: Using Pointers to Abstract Class

#include <iostream>
using namespace std;

// Abstract class with a pure virtual function
class Vehicle {
public:
    virtual void start() = 0; // Pure virtual function
};

// Derived class implementing the pure virtual function
class Car : public Vehicle {
public:
    void start() override {
        cout << "Car is starting" << endl; // Car start message
    }
};

// Another derived class implementing the pure virtual function
class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike is starting" << endl; // Bike start message
    }
};

int main() {
    Vehicle* v1 = new Car(); // Pointer to Vehicle, pointing to Car
    Vehicle* v2 = new Bike(); // Pointer to Vehicle, pointing to Bike

    v1->start(); // Output: Car is starting
    v2->start(); // Output: Bike is starting

    delete v1; // Clean up
    delete v2; // Clean up

    return 0;
}
