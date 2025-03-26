//3. Temperature Conversion

#include <iostream>

int main() {
    char choice;
    double celsius, fahrenheit;

    do {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> celsius;
        fahrenheit = (celsius * 9 / 5) + 32;
        std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

        std::cout << "Do you want to convert another temperature? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y'); // Continue if the user wants to convert again

    return 0;
}