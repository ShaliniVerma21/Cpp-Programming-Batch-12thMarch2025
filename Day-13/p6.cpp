/*
Definition: 
A virtual function in C++ is a member function in a base class that you expect to override in derived classes. 
When you use a base class pointer or reference to call a virtual function, C++ determines which function to 
invoke at runtime based on the type of the object being pointed to, rather than the type of the pointer.

Purpose: 
1. The primary purpose of virtual functions is to achieve runtime polymorphism. 
2. This allows for dynamic method resolution, enabling you to call derived class methods through base class 
pointers or references.

Syntax
To declare a virtual function, you use the virtual keyword in the base class.

class Base {
public:
    virtual void show() {
        // Base class implementation
    }
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    void show() override { // Override the base class method
        // Derived class implementation
    }
};
*/

#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show function called." << endl;
    }
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    void show() override { // Override the base class method
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    Base* b;           // Base class pointer
    Derived d;        // Derived class object
    b = &d;           // Pointing to derived class object

    b->show();        // Calls Derived's show() due to virtual function
    return 0;
}

