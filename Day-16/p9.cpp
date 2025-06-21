//Example 2: Multiple Derived Classes

#include <iostream>
using namespace std;

// Abstract class with a pure virtual function
class Animal {
public:
    virtual void sound() = 0; // Pure virtual function
};

// Derived class implementing the pure virtual function
class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof!" << endl; // Dog sound
    }
};

// Another derived class implementing the pure virtual function
class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow!" << endl; // Cat sound
    }
};

int main() {
    Dog dog; // Create a Dog object
    Cat cat; // Create a Cat object

    dog.sound(); // Output: Woof!
    cat.sound(); // Output: Meow!

    return 0;
}
