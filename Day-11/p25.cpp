//Vehicle Inheritance

#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    void start() {
        cout << brand << " is starting." << endl;
    }

    void stop() {
        cout << brand << " is stopping." << endl;
    }
};

// Derived class: Car (Single Inheritance)
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(string b, int s, int doors) : Vehicle(b, s), numberOfDoors(doors) {}

    void displayCarInfo() {
        cout << "Car Information:" << endl;
        displayInfo(); // Call base class method
        cout << "Number of doors: " << numberOfDoors << endl;
    }
};

// Derived class: Bike (Single Inheritance)
class Bike : public Vehicle {
private:
    string type;

public:
    Bike(string b, int s, string t) : Vehicle(b, s), type(t) {}

    void displayBikeInfo() {
        cout << "Bike Information:" << endl;
        displayInfo(); // Call base class method
        cout << "Type: " << type << endl;
    }
};

// Derived class: Truck (Multilevel Inheritance)
class Truck : public Vehicle {
private:
    int loadCapacity;

public:
    Truck(string b, int s, int capacity) : Vehicle(b, s), loadCapacity(capacity) {}

    void displayTruckInfo() {
        cout << "Truck Information:" << endl;
        displayInfo(); // Call base class method
        cout << "Load capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    // Create objects of derived classes
    Car myCar("Toyota", 180, 4);
    Bike myBike("Yamaha", 120, "Sport");
    Truck myTruck("Volvo", 100, 10);

    // Display information for each vehicle
    myCar.start();
    myCar.displayCarInfo();
    myCar.stop();

    cout << endl; // Just for spacing

    myBike.start();
    myBike.displayBikeInfo();
    myBike.stop();

    cout << endl; // Just for spacing

    myTruck.start();
    myTruck.displayTruckInfo();
    myTruck.stop();

    return 0;
}