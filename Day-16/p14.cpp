//Example 1: Basic Polymorphism with Function Overriding

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to allow overriding
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Overriding the sound function
    void sound() override {
        cout << "Bark" << endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    // Overriding the sound function
    void sound() override {
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog(); // Pointer of base class pointing to derived class
    Animal* animal2 = new Cat(); // Pointer of base class pointing to another derived class

    animal1->sound(); // Calls Dog's sound
    animal2->sound(); // Calls Cat's sound

    // Clean up
    delete animal1;
    delete animal2;

    return 0;
}
