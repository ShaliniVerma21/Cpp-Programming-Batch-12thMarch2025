//4. Multilevel Inheritance (Example: Vehicle, Car, and SportsCar)

#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle started." << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving." << endl;
    }
};

// Further derived class
class SportsCar : public Car {
public:
    void accelerate() {
        cout << "Sports car is accelerating." << endl;
    }
};

int main() {
    SportsCar mySportsCar;
    mySportsCar.start();      // From Vehicle
    mySportsCar.drive();      // From Car
    mySportsCar.accelerate(); // SportsCar's own method
    return 0;
}