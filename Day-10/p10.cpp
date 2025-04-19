//10. Light Bulb Class

#include <iostream>
using namespace std;

class LightBulb {
private:
    bool isOn;

public:
    LightBulb() {
        isOn = false;
    }

    void turnOn() {
        isOn = true;
        cout << "Light Bulb is ON" << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Light Bulb is OFF" << endl;
    }

    void displayStatus() {
        cout << "Light Bulb is currently " << (isOn ? "ON" : "OFF") << endl;
    }
};

int main() {
    LightBulb bulb;
    bulb.displayStatus();
    bulb.turnOn();
    bulb.displayStatus();
    bulb.turnOff();
    bulb.displayStatus();
    return 0;
}