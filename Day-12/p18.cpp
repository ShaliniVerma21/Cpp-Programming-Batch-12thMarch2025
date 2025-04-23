//Robot Simulation with Obstacles

#include <iostream>
#include <vector>
#include <string>
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

// Class for the grid
class Grid {
private:
    int width; // Width of the grid
    int height; // Height of the grid
    vector<vector<bool>> obstacles; // 2D vector to represent obstacles

public:
    // Constructor for Grid
    Grid(int w, int h) : width(w), height(h) {
        obstacles.resize(height, vector<bool>(width, false)); // Initialize grid without obstacles
    }

    // Function to add an obstacle
    void addObstacle(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            throw out_of_range("Obstacle position is out of grid bounds.");
        }
        obstacles[y][x] = true; // Mark the position as an obstacle
    }

    // Function to check if a position is an obstacle
    bool isObstacle(int x, int y) const {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return false; // Out of bounds is not considered an obstacle
        }
        return obstacles[y][x];
    }

    // Function to display the grid
    void display() const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (isObstacle(x, y)) {
                    cout << "X "; // Obstacle
                } else {
                    cout << ". "; // Free space
                }
            }
            cout << endl;
        }
    }
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    Position position; // Current position of the robot
    Direction direction; // Current direction of the robot
    Grid& grid; // Reference to the grid

public:
    // Constructor for Robot
    Robot(const string& n, int x, int y, Direction d, Grid& g) 
        : name(n), position(x, y), direction(d), grid(g) {}

    // Function to move the robot forward
    void moveForward() {
        Position newPosition = position; // Store the new position

        // Calculate new position based on current direction
        switch (direction) {
            case Direction::NORTH: newPosition.y -= 1; break;
            case Direction::EAST: newPosition.x += 1; break;
            case Direction::SOUTH: newPosition.y += 1; break;
            case Direction::WEST: newPosition.x -= 1; break;
            default: throw invalid_argument("Unknown direction.");
        }

        // Check for obstacles
        if (grid.isObstacle(newPosition.x, newPosition.y)) {
            cout << "Obstacle detected! Cannot move forward." << endl;
        } else {
            position = newPosition; // Update position if no obstacle
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

// // Derived class for a specific type of Robot
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n, int x, int y, Direction d, Grid& g) 
        : Robot(n, x, y, d, g) {}

    // Overriding the displayStatus function to include additional information
    void displayStatus() const override {
        Robot::displayStatus(); // Call base class method
        cout << "This is an advanced robot with enhanced capabilities." << endl;
    }

    // Function to move the robot backward
    void moveBackward() {
        Position newPosition = position; // Store the new position

        // Calculate new position based on current direction
        switch (direction) {
            case Direction::NORTH: newPosition.y += 1; break;
            case Direction::EAST: newPosition.x -= 1; break;
            case Direction::SOUTH: newPosition.y -= 1; break;
            case Direction::WEST: newPosition.x += 1; break;
            default: throw invalid_argument("Unknown direction.");
        }

        // Check for obstacles
        if (grid.isObstacle(newPosition.x, newPosition.y)) {
            cout << "Obstacle detected! Cannot move backward." << endl;
        } else {
            position = newPosition; // Update position if no obstacle
        }
    }
};

// Main function to demonstrate the robot simulation
int main() {
    Grid grid(5, 5); // Create a 5x5 grid
    grid.addObstacle(2, 2); // Add an obstacle at (2, 2)

    AdvancedRobot robot("Robo1", 0, 0, Direction::EAST, grid); // Create an advanced robot

    // Display initial status
    robot.displayStatus();
    grid.display();

    // Move the robot and display status
    robot.moveForward();
    robot.displayStatus();
    grid.display();

    robot.turnRight();
    robot.moveForward();
    robot.displayStatus();
    grid.display();

    robot.moveBackward();
    robot.displayStatus();
    grid.display();

    return 0; // End of the program
}