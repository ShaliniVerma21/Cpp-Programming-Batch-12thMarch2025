//3. Abstraction

#include <iostream>
using namespace std;

class AbstractShape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Square : public AbstractShape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    AbstractShape* shape = new Square();
    shape->draw(); // Calls Square's draw method
    delete shape;
    return 0;
}