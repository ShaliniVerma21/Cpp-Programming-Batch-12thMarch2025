//Example 1: Basic Pure Virtual Function

#include <iostream>
using namespace std;

// Abstract class with a pure virtual function
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0; // = 0 makes this a pure virtual function
};

// Derived class that implements the pure virtual function
class Circle : public Shape {
public:
    void draw() override { // Override the pure virtual function
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    Circle circle; // Create an object of Circle
    circle.draw(); // Call the draw function
    return 0;
}
