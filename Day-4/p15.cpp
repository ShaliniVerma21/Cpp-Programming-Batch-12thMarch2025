//10. Temperature Conversion (Celsius to Fahrenheit)

#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of temperatures to convert: ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        double celsius;
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> celsius;
        double fahrenheit = (celsius * 9/5) + 32;
        std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;
    }
    return 0;
}