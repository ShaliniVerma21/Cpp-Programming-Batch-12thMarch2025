// 3. Polymorphism (Function Overriding using Virtual Functions)

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing shape..." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle..." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing square..." << endl;
    }
};

void displayDrawing(Shape* s) {
    s->draw();
}

int main() {
    Circle c;
    Square s;

    displayDrawing(&c);
    displayDrawing(&s);
    return 0;
}
