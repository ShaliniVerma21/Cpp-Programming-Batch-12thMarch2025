//3. Multiple Derived Classes (Polymorphism with Different Behaviors)

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // abstraction
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle." << endl;
    }
};

void render(Shape* s) {
    s->draw();
}

int main() {
    Circle c;
    Rectangle r;

    render(&c);
    render(&r);

    return 0;
}
