//3. Battery Level Monitoring

#include <iostream>

int main() {
    int batteryLevel;

    std::cout << "Enter the battery level (0-100): ";
    std::cin >> batteryLevel;

    if (batteryLevel < 20) {
        std::cout << "Battery low! Returning to charging station." << std::endl;
    } else {
        std::cout << "Battery level is sufficient. Continuing operation." << std::endl;
    }

    return 0;
}