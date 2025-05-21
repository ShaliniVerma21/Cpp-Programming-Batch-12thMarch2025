//2. Polymorphism with Virtual Functions

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound." << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Animal* a;
    Cat c;
    a = &c;
    a->sound(); // Calls Cat's sound() due to polymorphism
    return 0;
}
