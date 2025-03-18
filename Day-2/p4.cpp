//Program: Check if a Number is Positive, Negative, or Zero
#include <iostream>

int main() {
    int number; // Declare an integer variable

    std::cout << "Enter a number: "; // Prompt the user for input
    std::cin >> number; // Read the number from the user

    // Check if the number is positive, negative, or zero
    if (number > 0) {
        std::cout << "The number is positive." << std::endl; // Output if the number is positive
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl; // Output if the number is negative
    } else {
        std::cout << "The number is zero." << std::endl; // Output if the number is zero
    }

    return 0; // Indicate successful completion
}