//goto

#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    int number;

    start: // Label for goto
    std::cout << "Please enter a positive integer: ";
    
    // Check if the input is valid
    if (!(std::cin >> number) || number < 0) {
        std::cout << "Invalid input! Please enter a valid positive integer." << std::endl;
        
        // Clear the error flag on cin
        std::cin.clear();
        // Ignore the rest of the line to discard invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        goto start; // Jump back to the input prompt
    }

    std::cout << "You entered: " << number << std::endl;
    return 0;
}