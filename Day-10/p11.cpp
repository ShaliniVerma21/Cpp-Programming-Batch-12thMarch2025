//Robot Class Example

#include <iostream>
using namespace std;

class Robot {
private:
    string name;
    string model;
    int batteryLevel; // Battery level in percentage

public:
    // Constructor
    Robot(string n, string m) {
        name = n;
        model = m;
        batteryLevel = 100; // Start with a full battery
    }

    // Method to move the robot
    void move(int distance) {
        if (batteryLevel > 0) {
            cout << name << " is moving " << distance << " meters." << endl;
            batteryLevel -= distance / 10; // Assume 10 meters consumes 1% battery
            if (batteryLevel < 0) batteryLevel = 0; // Prevent negative battery
        } else {
            cout << name << " cannot move. Battery is empty!" << endl;
        }
    }

    // Method to charge the robot
    void charge(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100; // Max battery level is 100%
        cout << name << " is charging. Current battery level: " << batteryLevel << "%" << endl;
    }

    // Method to display robot status
    void displayStatus() {
        cout << "Robot Name: " << name << ", Model: " << model << ", Battery Level: " << batteryLevel << "%" << endl;
    }
};

int main() {
    // Creating an object of Robot
    Robot myRobot("RoboMaster", "RX-100");

    // Displaying initial status
    myRobot.displayStatus();

    // Moving the robot
    myRobot.move(50); // Move 50 meters
    myRobot.displayStatus();

    // Charging the robot
    myRobot.charge(30);
    myRobot.displayStatus();

    // Attempting to move again
    myRobot.move(100); // Move 100 meters
    myRobot.displayStatus();

    return 0;
}