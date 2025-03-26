//4. Speed Control Based on Terrain

#include <iostream>
#include <string>

int main() {
    std::string terrain;
    int speed;

    std::cout << "Enter the type of terrain (flat, hilly, rough): ";
    std::cin >> terrain;

    if (terrain == "flat") {
        speed = 10; // Speed in meters per second
    } else if (terrain == "hilly") {
        speed = 5;
    } else if (terrain == "rough") {
        speed = 3;
    } else {
        std::cout << "Invalid terrain type!" << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "Setting speed to " << speed << " m/s for " << terrain << " terrain." << std::endl;

    return 0;
}