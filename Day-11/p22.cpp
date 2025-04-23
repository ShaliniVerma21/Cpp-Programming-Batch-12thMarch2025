//3. Hierarchical Inheritance(Example: Shape and its derived classes)

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void draw() {
        cout << "Drawing shape." << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing circle." << endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    void draw() {
        cout << "Drawing square." << endl;
    }
};

int main() {
    Circle myCircle;
    Square mySquare;
    myCircle.draw(); // Circle's draw method
    mySquare.draw(); // Square's draw method
    return 0;
}