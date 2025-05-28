//2. Polymorphism

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw(); // Calls Circle's draw method
    delete shape;
    return 0;
}