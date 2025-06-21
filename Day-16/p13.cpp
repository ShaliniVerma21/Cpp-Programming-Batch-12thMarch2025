//Example 3: Scoped Enumeration in a Switch Statement

#include <iostream>

// Define a scoped enumeration for traffic lights
enum class TrafficLight {
    Red,
    Yellow,
    Green
};

int main() {
    // Create a variable of type TrafficLight
    TrafficLight light = TrafficLight::Red;

    // Use a switch statement to determine the action based on the traffic light
    switch (light) {
        case TrafficLight::Red:
            std::cout << "Stop!" << std::endl;
            break;
        case TrafficLight::Yellow:
            std::cout << "Caution!" << std::endl;
            break;
        case TrafficLight::Green:
            std::cout << "Go!" << std::endl;
            break;
    }

    return 0;
}
