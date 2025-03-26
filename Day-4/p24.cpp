/*
Here are 5 unique real-world simplified C++ programs that incorporate basic C++ concepts, 
operators, and conditional statements, specifically tailored to robotics logic.
*/

//1. Obstacle Detection

#include <iostream>

int main() {
    float distance;

    std::cout << "Enter the distance to the obstacle (in meters): ";
    std::cin >> distance;

    if (distance < 0.5) {
        std::cout << "Obstacle detected! Stopping the robot." << std::endl;
    } else {
        std::cout << "Path is clear. Moving forward." << std::endl;
    }

    return 0;
}