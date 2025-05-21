//6. Shape Area Calculation Using Polymorphism

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0; // abstraction
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() override {
        return side * side;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.1416 * radius * radius;
    }
};

int main() {
    Shape* shape1 = new Square(4);
    Shape* shape2 = new Circle(3);

    cout << "Square area: " << shape1->area() << endl;
    cout << "Circle area: " << shape2->area() << endl;

    delete shape1;
    delete shape2;
    return 0;
}