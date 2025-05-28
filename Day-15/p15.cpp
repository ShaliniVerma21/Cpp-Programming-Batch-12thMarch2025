//1. Inheritance

#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks!" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks!" << endl;
    }
};

int main() {
    Dog dog;
    dog.speak(); // Inherited method
    dog.bark();  // Dog's own method
    return 0;
}