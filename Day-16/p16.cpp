//Example 3: Polymorphism with Abstract Classes

#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0; // No implementation, must be overridden
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived class
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle(); // Pointer of base class pointing to Circle
    Shape* shape2 = new Square(); // Pointer of base class pointing to Square

    shape1->draw(); // Calls Circle's draw
    shape2->draw(); // Calls Square's draw

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
