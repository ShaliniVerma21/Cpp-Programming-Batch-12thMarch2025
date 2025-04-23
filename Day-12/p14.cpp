//Robot Specifications

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For setting precision
#include <cmath> // For mathematical functions

using namespace std;

// Enumeration for robot types
enum class RobotType {
    HUMANOID,
    INDUSTRIAL,
    SERVICE,
    MILITARY
};

// Structure for robot specifications
struct RobotSpecs {
    string name; // Name of the robot
    double weight; // Weight of the robot in kg
    double height; // Height of the robot in meters
    double batteryLife; // Battery life in hours
    RobotType type; // Type of the robot

    // Constructor for RobotSpecs
    RobotSpecs(string n, double w, double h, double b, RobotType t)
        : name(n), weight(w), height(h), batteryLife(b), type(t) {}
};

// Base class for Robot
class Robot {
protected:
    RobotSpecs specs; // Specifications of the robot

public:
    // Constructor for Robot
    Robot(const RobotSpecs& s) : specs(s) {}

    // Function to display robot specifications
    virtual void displaySpecs() const {
        cout << "Robot Name: " << specs.name << endl;
        cout << "Weight: " << specs.weight << " kg" << endl;
        cout << "Height: " << specs.height << " m" << endl;
        cout << "Battery Life: " << specs.batteryLife << " hours" << endl;
        cout << "Type: " << getRobotTypeString(specs.type) << endl;
    }

    // Function to get string representation of robot type
    string getRobotTypeString(RobotType type) const {
        switch (type) {
            case RobotType::HUMANOID: return "Humanoid";
            case RobotType::INDUSTRIAL: return "Industrial";
            case RobotType::SERVICE: return "Service";
            case RobotType::MILITARY: return "Military";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for HumanoidRobot
class HumanoidRobot : public Robot {
public:
    // Constructor for HumanoidRobot
    HumanoidRobot(const RobotSpecs& s) : Robot(s) {}

    // Function to display humanoid robot specifications
    void displaySpecs() const override {
        cout << "Humanoid Robot Specifications:\n";
        Robot::displaySpecs();
    }
};

// Derived class for IndustrialRobot
class IndustrialRobot : public Robot {
public:
    // Constructor for IndustrialRobot
    IndustrialRobot(const RobotSpecs& s) : Robot(s) {}

    // Function to display industrial robot specifications
    void displaySpecs() const override {
        cout << "Industrial Robot Specifications:\n";
        Robot::displaySpecs();
    }
};

// Derived class for ServiceRobot
class ServiceRobot : public Robot {
public:
    // Constructor for ServiceRobot
    ServiceRobot(const RobotSpecs& s) : Robot(s) {}

    // Function to display service robot specifications
    void displaySpecs() const override {
        cout << "Service Robot Specifications:\n";
        Robot::displaySpecs();
    }
};

// Derived class for MilitaryRobot
class MilitaryRobot : public Robot {
public:
    // Constructor for MilitaryRobot
    MilitaryRobot(const RobotSpecs& s) : Robot(s) {}

    // Function to display military robot specifications
    void displaySpecs() const override {
        cout << "Military Robot Specifications:\n";
        Robot::displaySpecs();
    }
};

int main() {
    // Create instances of different types of robots
    HumanoidRobot humanoid(RobotSpecs("Atlas", 80.0, 1.8, 24.0, RobotType::HUMANOID));
    IndustrialRobot industrial(RobotSpecs("RoboArm", 150.0, 1.5, 12.0, RobotType::INDUSTRIAL));
    ServiceRobot service(RobotSpecs("Roomba", 3.5, 0.1, 2.0, RobotType::SERVICE));
    MilitaryRobot military(RobotSpecs("Drone-X", 10.0, 0.5, 5.0, RobotType::MILITARY));

    // Display specifications of each robot
    humanoid.displaySpecs();
    cout << endl;

    industrial.displaySpecs();
    cout << endl;

    service.displaySpecs();
    cout << endl;

    military.displaySpecs();
    cout << endl;

    return 0;
}