#include <iostream>

// Find the Largest of Three Numbers

int main()
{
    int num1, num2;
    std::cout << "Enter two numbers: "; // Prompt user for input
    std::cin >> num1 >> num2;           // Read three integers
    // Determine the largest number
    int largest1 = (num1 > num2) ? num1 : num2;
    std::cout << "\nThe largest number is: " << largest1 <<"\n\n"; // Output the result

    int a, b, c; // Declare three integer variables

    std::cout << "Enter three numbers: "; // Prompt user for input
    std::cin >> a >> b >> c;              // Read three integers

    // Determine the largest number
    int largest = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    std::cout << "The largest number is: " << largest << std::endl; // Output the result

    return 0; // Indicate successful completion
}