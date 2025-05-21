//1. Basic Abstraction Using Pure Virtual Function

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0; // Pure virtual function -> abstraction
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks." << endl;
    }
};

int main() {
    Dog d;
    d.sound();
    return 0;
}
