// 1. Class, Object, and Function

#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void start() {
        cout << brand << " is starting." << endl;
    }

    void setSpeed(int s) {
        speed = s;
        cout << brand << " is running at " << speed << " km/h." << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";
    myCar.start();
    myCar.setSpeed(80);
    return 0;
}
