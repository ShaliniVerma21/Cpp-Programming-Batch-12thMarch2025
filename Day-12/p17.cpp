//Robot Navigation System

#include <iostream>
#include <string>
#include <cmath> // For mathematical functions
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for directions
enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Structure for the robot's position
struct Position {
    int x; // X-coordinate
    int y; // Y-coordinate

    // Constructor for Position
    Position(int xCoord = 0, int yCoord = 0) : x(xCoord), y(yCoord) {}
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    Position position; // Current position of the robot
    Direction direction; // Current direction of the robot

public:
    // Constructor for Robot
    Robot(const string& n, int x, int y, Direction d) 
        : name(n), position(x, y), direction(d) {}

    // Function to move the robot forward
    void moveForward(int steps) {
        switch (direction) {
            case Direction::NORTH:
                position.y += steps;
                break;
            case Direction::EAST:
                position.x += steps;
                break;
            case Direction::SOUTH:
                position.y -= steps;
                break;
            case Direction::WEST:
                position.x -= steps;
                break;
            default:
                throw invalid_argument("Unknown direction.");
        }
    }

    // Function to turn the robot to the left
    void turnLeft() {
        direction = static_cast<Direction>((static_cast<int>(direction) + 3) % 4);
    }

    // Function to turn the robot to the right
    void turnRight() {
        direction = static_cast<Direction>((static_cast<int>(direction) + 1) % 4);
    }

    // Function to display the robot's current status
    virtual void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        cout << "Current Position: (" << position.x << ", " << position.y << ")" << endl;
        cout << "Current Direction: " << getDirectionString(direction) << endl;
    }

    // Function to get string representation of direction
    string getDirectionString(Direction dir) const {
        switch (dir) {
            case Direction::NORTH: return "North";
            case Direction::EAST: return "East";
            case Direction::SOUTH: return "South";
            case Direction::WEST: return "West";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for AdvancedRobot
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n, int x, int y, Direction d) 
        : Robot(n, x, y, d) {}

    // Function to display the advanced robot's status
    void displayStatus() const override {
        cout << "Advanced Robot Status:\n";
        Robot::displayStatus();
    }
};

int main() {
    // Create an instance of Robot
    Robot simpleRobot("SimpleBot", 0, 0, Direction::NORTH);
    
    // Move the robot and display its status
    simpleRobot.moveForward(5);
    simpleRobot.turnRight();
    simpleRobot.moveForward(3);
    simpleRobot.displayStatus();
    
    cout << endl;

    // Create an instance of AdvancedRobot
    AdvancedRobot advancedRobot("AdvancedBot", 2, 2, Direction::EAST);
    
    // Move the advanced robot and display its status
    advancedRobot.moveForward(4);
    advancedRobot.turnLeft();
    advancedRobot.moveForward(2);
    advancedRobot.displayStatus();

    return 0;
}