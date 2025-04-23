//Robot Arm Control

#include <iostream>
#include <string>
#include <cmath> // For mathematical functions
#include <iomanip> // For setting precision
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for joint types
enum class JointType {
    ROTATIONAL,
    PRISMATIC
};

// Structure for joint specifications
struct JointSpecs {
    JointType type; // Type of joint
    double angle; // Angle for rotational joints (in degrees)
    double position; // Position for prismatic joints (in meters)

    // Constructor for JointSpecs
    JointSpecs(JointType t, double a = 0.0, double p = 0.0) 
        : type(t), angle(a), position(p) {}
};

// Base class for RobotArm
class RobotArm {
protected:
    string name; // Name of the robot arm
    JointSpecs joint; // Specifications of the joint

public:
    // Constructor for RobotArm
    RobotArm(const string& n, const JointSpecs& j) : name(n), joint(j) {}

    // Function to move the joint
    void moveJoint(double value) {
        if (joint.type == JointType::ROTATIONAL) {
            joint.angle += value;
            joint.angle = fmod(joint.angle, 360.0); // Keep angle within 0-360 degrees
        } else if (joint.type == JointType::PRISMATIC) {
            joint.position += value;
        } else {
            throw invalid_argument("Unknown joint type.");
        }
    }

    // Function to display the status of the robot arm
    virtual void displayStatus() const {
        cout << "Robot Arm Name: " << name << endl;
        if (joint.type == JointType::ROTATIONAL) {
            cout << "Joint Type: Rotational, Angle: " << fixed << setprecision(2) << joint.angle << " degrees" << endl;
        } else if (joint.type == JointType::PRISMATIC) {
            cout << "Joint Type: Prismatic, Position: " << fixed << setprecision(2) << joint.position << " meters" << endl;
        }
    }

    // Virtual destructor
    virtual ~RobotArm() {}
};

// Derived class for MultiJointRobotArm
class MultiJointRobotArm : public RobotArm {
private:
    int numberOfJoints; // Number of joints in the robot arm

public:
    // Constructor for MultiJointRobotArm
    MultiJointRobotArm(const string& n, const JointSpecs& j, int numJoints) 
        : RobotArm(n, j), numberOfJoints(numJoints) {}

    // Function to display the status of the multi-joint robot arm
    void displayStatus() const override {
        RobotArm::displayStatus();
        cout << "Number of Joints: " << numberOfJoints << endl;
    }
};

int main() {
    // Create a rotational joint for the robot arm
    JointSpecs rotationalJoint(JointType::ROTATIONAL, 45.0);
    RobotArm robotArm("Arm1", rotationalJoint);

    // Move the joint
    robotArm.moveJoint(30.0); // Move by 30 degrees
    robotArm.displayStatus(); // Display status

    cout << endl;

    // Create a prismatic joint for a multi-joint robot arm
    JointSpecs prismaticJoint(JointType::PRISMATIC, 0.0, 1.0);
    MultiJointRobotArm multiJointArm("MultiArm1", prismaticJoint, 3);

    // Move the joint
    multiJointArm.moveJoint(0.5); // Move by 0.5 meters
    multiJointArm.displayStatus(); // Display status

    return 0;
}