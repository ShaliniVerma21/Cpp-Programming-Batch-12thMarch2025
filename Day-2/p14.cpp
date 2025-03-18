//Program 1: Simple Robot Movement
#include <iostream>
#include <string>

class Robot {
public:
    int x, y; // Robot's position

    Robot() : x(0), y(0) {} // Initialize position at (0, 0)

    void moveForward() {
        y++;
        std::cout << "Moved forward to (" << x << ", " << y << ")\n";
    }

    void moveBackward() {
        y--;
        std::cout << "Moved backward to (" << x << ", " << y << ")\n";
    }

    void moveLeft() {
        x--;
        std::cout << "Moved left to (" << x << ", " << y << ")\n";
    }

    void moveRight() {
        x++;
        std::cout << "Moved right to (" << x << ", " << y << ")\n";
    }

    void displayPosition() {
        std::cout << "Current position: (" << x << ", " << y << ")\n";
    }
};

int main() {
    Robot myRobot;
    std::string command;

    std::cout << "Robot Control Program\n";
    std::cout << "Commands: forward, backward, left, right, status, exit\n";

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "forward") {
            myRobot.moveForward();
        } else if (command == "backward") {
            myRobot.moveBackward();
        } else if (command == "left") {
            myRobot.moveLeft();
        } else if (command == "right") {
            myRobot.moveRight();
        } else if (command == "status") {
            myRobot.displayPosition();
        } else if (command == "exit") {
            std::cout << "Exiting the program.\n";
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}