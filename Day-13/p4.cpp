//2. Run-time Polymorphism
// Using Inheritance and Virtual Functions:

#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show function called." << endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Override the base class function
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    Base* b;           // Base class pointer
    Derived d;        // Derived class object
    b = &d;           // Pointing to derived class object

    b->show();        // Calls Derived's show() due to polymorphism
    return 0;
}