//Robot Emergency Stop System

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory> // For smart pointers

using namespace std;

// Enumeration for robot status
enum class RobotStatus {
    ACTIVE,
    INACTIVE,
    EMERGENCY_STOP
};

// Structure for emergency stop signal
struct EmergencyStopSignal {
    bool isActive; // Indicates if the emergency stop is active

    // Constructor for EmergencyStopSignal
    EmergencyStopSignal(bool active = false) : isActive(active) {}
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    RobotStatus status; // Current status of the robot

public:
    // Constructor for Robot
    Robot(const string& n) : name(n), status(RobotStatus::ACTIVE) {}

    // Function to activate the robot
    void activate() {
        status = RobotStatus::ACTIVE;
        cout << name << " is now active." << endl;
    }

    // Function to deactivate the robot
    void deactivate() {
        status = RobotStatus::INACTIVE;
        cout << name << " is now inactive." << endl;
    }

    // Function to handle emergency stop
    virtual void emergencyStop() {
        status = RobotStatus::EMERGENCY_STOP;
        cout << name << " has stopped due to emergency." << endl;
    }

    // Function to display the robot's status
    void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        cout << "Current Status: " << getStatusString(status) << endl;
    }

    // Function to get string representation of status
    string getStatusString(RobotStatus s) const {
        switch (s) {
            case RobotStatus::ACTIVE: return "Active";
            case RobotStatus::INACTIVE: return "Inactive";
            case RobotStatus::EMERGENCY_STOP: return "Emergency Stop";
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
    AdvancedRobot(const string& n) : Robot(n) {}

    // Overriding emergencyStop to include additional behavior
    void emergencyStop() override {
        Robot::emergencyStop(); // Call base class method
        // Additional behavior for advanced robot
        cout << "Advanced safety protocols activated for " << name << "." << endl;
    }
};

// Class for Emergency Stop System
class EmergencyStopSystem {
private:
    unique_ptr<Robot> robot; // Pointer to the robot
    EmergencyStopSignal stopSignal; // Emergency stop signal

public:
    // Constructor for EmergencyStopSystem
    EmergencyStopSystem(unique_ptr<Robot> r) : robot(move(r)), stopSignal() {}

    // Function to activate the emergency stop
    void activateEmergencyStop() {
        stopSignal.isActive = true;
        robot->emergencyStop();
    }

    // Function to check the robot's status
    void checkRobotStatus() const {
        robot->displayStatus();
    }
};

int main() {
    // Create an advanced robot
    unique_ptr<Robot> robot = make_unique<AdvancedRobot>("RoboGuard");

    // Create an emergency stop system with the robot
    EmergencyStopSystem emergencySystem(move(robot));

    // Activate the robot and check its status
    emergencySystem.checkRobotStatus();
    emergencySystem.activateEmergencyStop(); // Trigger emergency stop

    return 0; // End of the program
}