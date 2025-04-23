//Robot Vision System

#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
#include <cmath> // For mathematical functions

using namespace std;

// Enumeration for object types detected by the robot
enum class ObjectType {
    NONE,
    PERSON,
    ANIMAL,
    VEHICLE,
    UNKNOWN
};

// Structure for a detected object
struct DetectedObject {
    ObjectType type; // Type of the detected object
    float confidence; // Confidence level of detection (0.0 to 1.0)
    float x; // X-coordinate of the object
    float y; // Y-coordinate of the object

    // Constructor for DetectedObject
    DetectedObject(ObjectType t, float conf, float xCoord, float yCoord)
        : type(t), confidence(conf), x(xCoord), y(yCoord) {}
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    vector<DetectedObject> detectedObjects; // List of detected objects

public:
    // Constructor for Robot
    Robot(const string& n) : name(n) {}

    // Function to process an image and detect objects
    virtual void processImage() {
        // Simulate object detection (in a real scenario, this would involve complex algorithms)
        detectedObjects.push_back(DetectedObject(ObjectType::PERSON, 0.95, 100.0, 150.0));
        detectedObjects.push_back(DetectedObject(ObjectType::ANIMAL, 0.85, 200.0, 250.0));
        detectedObjects.push_back(DetectedObject(ObjectType::VEHICLE, 0.90, 300.0, 350.0));
    }

    // Function to display detected objects
    void displayDetectedObjects() const {
        cout << "Detected Objects for " << name << ":\n";
        for (const auto& obj : detectedObjects) {
            cout << "Type: " << getObjectTypeString(obj.type)
                 << ", Confidence: " << obj.confidence
                 << ", Coordinates: (" << obj.x << ", " << obj.y << ")\n";
        }
    }

    // Function to get string representation of object type
    string getObjectTypeString(ObjectType type) const {
        switch (type) {
            case ObjectType::PERSON: return "Person";
            case ObjectType::ANIMAL: return "Animal";
            case ObjectType::VEHICLE: return "Vehicle";
            case ObjectType::UNKNOWN: return "Unknown";
            default: return "None";
        }
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for AdvancedRobot with enhanced vision capabilities
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n) : Robot(n) {}

    // Overriding processImage to include additional detection logic
    void processImage() override {
        Robot::processImage(); // Call base class method
        // Simulate additional detection logic
        detectedObjects.push_back(DetectedObject(ObjectType::UNKNOWN, 0.70, 400.0, 450.0));
    }

    // Function to calculate distance to detected objects
    void calculateDistances(float referenceX, float referenceY) const {
        cout << "Distances to detected objects from reference point (" << referenceX << ", " << referenceY << "):\n";
        for (const auto& obj : detectedObjects) {
            float distance = sqrt(pow(obj.x - referenceX, 2) + pow(obj.y - referenceY, 2));
            cout << "Distance to " << getObjectTypeString(obj.type) << ": " << distance << " units\n";
        }
    }
};

// Main function to demonstrate the robot vision system
int main() {
    // Create an advanced robot
    unique_ptr<Robot> robot = make_unique<AdvancedRobot>("VisionBot");

    // Process an image to detect objects
    robot->processImage();

    // Display detected objects
    robot->displayDetectedObjects();

    // Calculate distances to detected objects from a reference point
    static const float referenceX = 0.0f;
    static const float referenceY = 0.0f;
    dynamic_cast<AdvancedRobot*>(robot.get())->calculateDistances(referenceX, referenceY);

    return 0; // End of the program
}