//Robot Status Monitoring

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory> // For smart pointers

using namespace std;

// Enumeration for operational status
enum class OperationalStatus {
    ONLINE,
    OFFLINE,
    ERROR
};

// Enumeration for error codes
enum class ErrorCode {
    NONE,
    LOW_BATTERY,
    OVERHEATING,
    SENSOR_FAILURE
};

// Structure for battery status
struct BatteryStatus {
    int level; // Battery level in percentage (0-100)

    // Constructor for BatteryStatus
    BatteryStatus(int lvl = 100) : level(lvl) {
        if (level < 0 || level > 100) {
            throw invalid_argument("Battery level must be between 0 and 100.");
        }
    }
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    OperationalStatus status; // Current operational status
    BatteryStatus battery; // Battery status
    ErrorCode error; // Current error code

public:
    // Constructor for Robot
    Robot(const string& n, int batteryLevel) 
        : name(n), status(OperationalStatus::ONLINE), battery(batteryLevel), error(ErrorCode::NONE) {}

    // Function to display the robot's status
    void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        cout << "Operational Status: " << getStatusString(status) << endl;
        cout << "Battery Level: " << battery.level << "%" << endl;
        cout << "Error Code: " << getErrorString(error) << endl;
    }

    // Function to simulate battery drain
    void drainBattery(int amount) {
        if (amount < 0) {
            throw invalid_argument("Drain amount must be non-negative.");
        }
        battery.level -= amount;
        if (battery.level < 20) {
            error = ErrorCode::LOW_BATTERY; // Set error if battery is low
        }
    }

    // Function to simulate an operational error
    void triggerError(ErrorCode err) {
        error = err;
        status = OperationalStatus::ERROR; // Set status to ERROR
    }

    // Function to resolve an error
    void resolveError() {
        error = ErrorCode::NONE;
        status = OperationalStatus::ONLINE; // Set status back to ONLINE
    }

    // Function to get string representation of operational status
    string getStatusString(OperationalStatus s) const {
        switch (s) {
            case OperationalStatus::ONLINE: return "Online";
            case OperationalStatus::OFFLINE: return "Offline";
            case OperationalStatus::ERROR: return "Error";
            default: return "Unknown";
        }
    }

    // Function to get string representation of error code
    string getErrorString(ErrorCode e) const {
        switch (e) {
            case ErrorCode::NONE: return "No Error";
            case ErrorCode::LOW_BATTERY: return "Low Battery";
            case ErrorCode::OVERHEATING: return "Overheating";
            case ErrorCode::SENSOR_FAILURE: return "Sensor Failure";
            default: return "Unknown Error";
        }
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for AdvancedRobot
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n, int batteryLevel) 
        : Robot(n, batteryLevel) {}

    // Overriding displayStatus to include additional information
    void displayStatus() const override {
        Robot::displayStatus(); // Call base class method
        cout << "Advanced monitoring features enabled." << endl;
    }
};

// Main function to demonstrate the robot status monitoring system
int main() {
    // Create an advanced robot with a battery level of 100%
    unique_ptr<Robot> robot = make_unique<AdvancedRobot>("RoboMonitor", 100);

    // Display initial status
    robot->displayStatus();

    // Simulate battery drain
    robot->drainBattery(30);
    robot->displayStatus();

    // Simulate an error
    robot->triggerError(ErrorCode::OVERHEATING);
    robot->displayStatus();

    // Resolve the error
    robot->resolveError();
    robot->displayStatus();

    return 0; // End of the program
}