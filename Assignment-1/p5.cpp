//Problem 4: Simple Robot Control

#include <iostream>
using namespace std;

class Robot {
public:
    void moveForward() {
        cout << "Robot is moving forward." << endl;
    }
    void moveBackward() {
        cout << "Robot is moving backward." << endl;
    }
    void turnLeft() {
        cout << "Robot is turning left." << endl;
    }
    void turnRight() {
        cout << "Robot is turning right." << endl;
    }
};

int main() {
    Robot robot;
    int command;
    cout << "Enter command (1: Forward, 2: Backward, 3: Left, 4: Right): ";
    cin >> command;
    switch (command) {
        case 1: robot.moveForward(); break;
        case  2: robot.moveBackward(); break;
        case 3: robot.turnLeft(); break;
        case 4: robot.turnRight(); break;
        default: cout << "Invalid command!" << endl;
    }
    return 0;
}