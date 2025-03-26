//2. Temperature Control System

#include <iostream>

int main() {
    float temperature;

    std::cout << "Enter the current temperature (in Celsius): ";
    std::cin >> temperature;

    if (temperature > 75.0) {
        std::cout << "Temperature is too high! Activating cooling system." << std::endl;
    } else {
        std::cout << "Temperature is normal. No action needed." << std::endl;
    }

    return 0;
}