/*
Object-Oriented Programming (OOP): 

OOP is a way of writing computer programs using objects. 
An object is a combination of data and functions (actions) that work together.

Instead of writing code line by line (like in procedural programming), 
in OOP you create objects based on real-world entities — like a Car, BankAccount, Student, etc.

Real-Life Example: Car
====================================
Imagine you are working on a program for a car showroom.

A Car is an object.

A Car has:

Properties (Data): Color, Brand, Model, Price.

Actions (Functions): StartEngine(), StopEngine(), ApplyBrake().


Key Concepts of OOP:
--------------------

Class: 
A class is a blueprint or a template that defines the properties (attributes) and 
actions (methods) of an object. Example- Animal

Object: 
An instance of a class. It represents a specific entity with the properties 
and behaviors defined by its class. Example- Dog (properties - color, bread 
&  Behaviour - bark() , eating() )

4 pillars of oops : 

1. Encapsulation: 
The bundling of data (attributes) and methods (functions) that operate on the data 
into a single unit, or class. It restricts direct access to some of the object's components, 
which is a means of preventing unintended interference and misuse.

2. Inheritance: 
A mechanism where a new class (derived class) can inherit properties and behaviors 
from an existing class (base class). This promotes code reusability.

3. Polymorphism: 
The ability of different classes to be treated as instances of the same class through 
a common interface. It allows methods to do different things based on the object it is acting upon.

4. Abstraction: 
The concept of hiding complex implementation details and showing only the essential 
features of the object. It helps in reducing programming complexity.

Real-Life Example
-----------------
Let’s consider a real-life example of a Car.

Class: Car

Attributes: color, model, year, speed
Methods: accelerate(), brake(), displayInfo()
Object: myCar

color: "Red"
model: "Toyota"
year: 2020
speed: 0
*/


//1. Car Class


#include <iostream>
using namespace std;

// Class definition
class Car {
public:
    // Attributes
    string color;
    string model;
    int year;
    int speed;

    // Constructor
    Car(string c, string m, int y) {
        color = c;
        model = m;
        year = y;
        speed = 0; // Initial speed
    }

    // Method to accelerate
    void accelerate() {
        speed += 10;
        cout << "Accelerating. Current speed: " << speed << " km/h" << endl;
    }

    // Method to brake
    void brake() {
        speed -= 10;
        if (speed < 0) speed = 0; // Prevent negative speed
        cout << "Braking. Current speed: " << speed << " km/h" << endl;
    }

    // Method to display car information
    void displayInfo() {
        cout << "Car Model: " << model << ", Color: " << color << ", Year: " << year << ", Speed: " 
        << speed << " km/h" << endl;
    }
};

int main() {
    // Creating an object of Car
    Car myCar("Red", "Toyota", 2020);

    // Using methods
    myCar.displayInfo();
    myCar.accelerate();
    myCar.brake();
    myCar.displayInfo();

    return 0;
}