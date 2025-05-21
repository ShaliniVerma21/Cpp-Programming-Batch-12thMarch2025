//8. Device Control Using Abstraction and Polymorphism

#include <iostream>
using namespace std;

class Device {
public:
    virtual void turnOn() = 0;   // abstraction
    virtual void turnOff() = 0;
};

class TV : public Device {
public:
    void turnOn() override {
        cout << "TV is ON." << endl;
    }
    void turnOff() override {
        cout << "TV is OFF." << endl;
    }
};

class Radio : public Device {
public:
    void turnOn() override {
        cout << "Radio is ON." << endl;
    }
    void turnOff() override {
        cout << "Radio is OFF." << endl;
    }
};

void operate(Device* d) {
    d->turnOn();
    d->turnOff();
}

int main() {
    TV tv;
    Radio radio;

    operate(&tv);
    operate(&radio);

    return 0;
}
