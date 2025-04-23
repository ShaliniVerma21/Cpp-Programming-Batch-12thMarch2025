//Robot Voice Command System

#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
#include <algorithm> // For std::find
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for command types
enum class CommandType {
    MOVE,
    STOP,
    TURN_LEFT,
    TURN_RIGHT,
    STATUS,
    UNKNOWN
};

// Structure for a voice command
struct VoiceCommand {
    CommandType command; // Type of command
    string parameters; // Additional parameters for the command

    // Constructor for VoiceCommand
    VoiceCommand(CommandType cmd, const string& params = "")
        : command(cmd), parameters(params) {}
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    bool isMoving; // Indicates if the robot is currently moving

public:
    // Constructor for Robot
    Robot(const string& n) : name(n), isMoving(false) {}

    // Function to execute a command
    virtual void executeCommand(const VoiceCommand& command) {
        switch (command.command) {
            case CommandType::MOVE:
                move(command.parameters);
                break;
            case CommandType::STOP:
                stop();
                break;
            case CommandType::TURN_LEFT:
                turnLeft();
                break;
            case CommandType::TURN_RIGHT:
                turnRight();
                break;
            case CommandType::STATUS:
                displayStatus();
                break;
            default:
                cout << "Unknown command." << endl;
                break;
        }
    }

    // Function to move the robot
    void move(const string& direction) {
        isMoving = true;
        cout << name << " is moving " << direction << "." << endl;
    }

    // Function to stop the robot
    void stop() {
        isMoving = false;
        cout << name << " has stopped." << endl;
    }

    // Function to turn the robot left
    void turnLeft() {
        cout << name << " is turning left." << endl;
    }

    // Function to turn the robot right
    void turnRight() {
        cout << name << " is turning right." << endl;
    }

    // Function to display the robot's status
    void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        cout << "Current Status: " << (isMoving ? "Moving" : "Stopped") << endl;
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for AdvancedRobot with additional capabilities
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n) : Robot(n) {}

    // Overriding executeCommand to include additional behavior
    void executeCommand(const VoiceCommand& command) override {
        cout << "Executing command with advanced capabilities..." << endl;
        Robot::executeCommand(command); // Call base class method
    }
};

// Function to simulate voice command recognition
VoiceCommand recognizeVoiceCommand(const string& input) {
    if (input == "move forward") {
        return VoiceCommand(CommandType::MOVE, "forward");
    } else if (input == "move backward") {
        return VoiceCommand(CommandType::MOVE, "backward");
    } else if (input == "stop") {
        return VoiceCommand(CommandType::STOP);
    } else if (input == "turn left") {
        return VoiceCommand(CommandType::TURN_LEFT);
    } else if (input == "turn right") {
        return VoiceCommand(CommandType::TURN_RIGHT);
    } else if (input == "status") {
        return VoiceCommand(CommandType::STATUS);
    } else {
        return VoiceCommand(CommandType::UNKNOWN);
    }
}

// Main function to demonstrate the robot voice command system
int main() {
    // Create an advanced robot
    unique_ptr<Robot> robot = make_unique<AdvancedRobot>("VoiceBot");

    // Simulate voice commands
    vector<string> commands = {
        "move forward",
        "turn left",
        "move backward",
        "stop",
        "status",
        "turn right",
        "unknown command"
    };

    // Execute each command
    for (const auto& cmd : commands) {
        VoiceCommand command = recognizeVoiceCommand(cmd);
        robot->executeCommand(command);
    }

    return 0; // End of the program
}