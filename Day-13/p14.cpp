//5. Real-World Example Using All Concepts Together

#include <iostream>
using namespace std;

// Abstract base class (Abstraction)
class Vehicle {
public:
    virtual void start() = 0;  // Pure virtual function
    virtual void stop() = 0;
    virtual ~Vehicle() {} // Virtual destructor
};

// Derived class 1 (Inheritance + Polymorphism)
class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike started." << endl;
    }

    void stop() override {
        cout << "Bike stopped." << endl;
    }
};

// Derived class 2 (Inheritance + Polymorphism)
class Car : public Vehicle {
public:
    void start() override {
        cout << "Car started." << endl;
    }

    void stop() override {
        cout << "Car stopped." << endl;
    }
};

// Function using pointer to base class (Polymorphism)
void testVehicle(Vehicle* v) {
    v->start();
    v->stop();
}

int main() {
    Bike b;
    Car c;

    testVehicle(&b);
    testVehicle(&c);

    return 0;
}
