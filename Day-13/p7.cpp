/*
Types of Virtual Functions --> 

1. Pure Virtual Functions: A pure virtual function is declared by assigning 0 in its declaration. 
It makes the class abstract, meaning you cannot instantiate it directly.

Syntax:
virtual void show() = 0; // Pure virtual function

2. Virtual Destructor:A virtual destructor ensures that the destructor of the derived class is called 
when an object is deleted through a base class pointer.
*/

//Example of Pure Virtual Function

#include <iostream>
using namespace std;

class AbstractBase {
public:
    virtual void show() = 0; // Pure virtual function
};

class ConcreteDerived : public AbstractBase {
public:
    void show() override {
        cout << "ConcreteDerived class show function called." << endl;
    }
};

int main() {
    AbstractBase* ab = new ConcreteDerived();
    ab->show(); // Calls ConcreteDerived's show()
    delete ab;  // Clean up
    return 0;
}