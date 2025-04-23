/*
Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class 
(known as the derived class or child class) to inherit properties (data members) and behaviors 
(member functions) from another class (known as the base class or parent class). This mechanism 
promotes code reusability, reduces redundancy, and establishes a hierarchical relationship between classes.

Syntax:

class BaseClass {
    // Base class members
};

class DerivedClass : public BaseClass {
    // Derived class members
};

Key Concepts of Inheritance
1. Base Class: The class whose properties and methods are inherited.
2. Derived Class: The class that inherits from the base class. It can add new properties and methods or 
override existing ones.
3. Access Specifiers: Inheritance can be public, protected, or private, which determines the accessibility 
of the base class members in the derived class.

Types of Inheritance

1. Single Inheritance: A derived class inherits from a single base class.

2. Multiple Inheritance: A derived class inherits from multiple base classes.

3. Multilevel Inheritance: A derived class inherits from another derived class.

4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.

5. Hybrid Inheritance: A combination of two or more types of inheritance.

Access Specifiers in Inheritance -->

1.Public Inheritance: 
Public members of the base class remain public in the derived class, and protected members remain protected.

2.Protected Inheritance: 
Public and protected members of the base class become protected in the derived class.

3.Private Inheritance: 
Public and protected members of the base class become private in the derived class.

*/

//1. Single Inheritance (Example: Animal and Dog)

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void speak() {
        cout << "Animal speaks." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.speak(); // Inherited method
    myDog.bark();  // Dog's own method
    return 0;
}