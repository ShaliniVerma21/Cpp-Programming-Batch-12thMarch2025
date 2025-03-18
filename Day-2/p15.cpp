//Program 2: Robot with Basic Obstacle Detection
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Robot {
public:
    int x, y; // Robot's position
    bool obstacleDetected; // Flag for obstacle detection

    // Constructor to initialize position and obstacle flag
    Robot() : x(0), y(0), obstacleDetected(false) {}

    // Simulate obstacle detection
    void detectObstacle() {
        obstacleDetected = (rand() % 2 == 0); // Randomly detect an obstacle
    }

    // Move the robot forward if no obstacle is detected
    void moveForward() {
        detectObstacle(); // Check for obstacles before moving
        if (obstacleDetected) {
            std::cout << "Obstacle detected! Cannot move forward.\n";
        } else {
            y++; // Move forward in the y direction
            std::cout << "Moved forward to (" << x << ", " << y << ")\n";
        }
    }

    // Display the current position of the robot
    void displayPosition() {
        std::cout << "Current position: (" << x << ", " << y << ")\n";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    Robot myRobot; // Create a Robot object
    std::string command; // Variable to store user command

    std::cout << "Robot Control Program with Obstacle Detection\n";
    std::cout << "Commands: forward, status, exit\n";

    // Main loop to accept user commands
    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "forward") {
            myRobot.moveForward(); // Move the robot forward
        } else if (command == "status") {
            myRobot.displayPosition(); // Display the robot's current position
        } else if (command == "exit") {
            std::cout << "Exiting the program.\n";
            break; // Exit the loop and program
        } else {
            std::cout << "Invalid command. Please try again.\n"; // Handle invalid commands
        }
    }

    return 0; // Indicate successful completion
}