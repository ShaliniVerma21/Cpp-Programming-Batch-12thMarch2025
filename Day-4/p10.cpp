//for loop

//5. Factorial Calculator

#include <iostream>

int main() {
    int number;
    unsigned long long factorial = 1; // Use unsigned long long to handle large results

    // Ask the user for a non-negative integer
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    // Check if the input is valid
    if (number < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Calculate factorial using a for loop
        for (int i = 1; i <= number; ++i) {
            factorial *= i; // Multiply factorial by the current number
        }
        // Output the result
        std::cout << "Factorial of " << number << " = " << factorial << std::endl;
    }

    return 0;
}