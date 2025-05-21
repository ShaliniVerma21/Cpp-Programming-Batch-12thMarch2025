//4. Abstract Class with Multiple Functions

#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;   // abstraction
    virtual void stop() = 0;
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike started." << endl;
    }
    void stop() override {
        cout << "Bike stopped." << endl;
    }
};

int main() {
    Bike b;
    b.start();
    b.stop();
    return 0;
}
