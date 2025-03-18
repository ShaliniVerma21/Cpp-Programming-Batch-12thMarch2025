#include <iostream>
// Include the iostream library for input and output

/*
Multiline Comments
*/
int main() {
    int a, b, sum; // Declare three integer variables

    std::cout << "Enter two numbers: "; // Prompt the user for input
    std::cin >> a >> b; // Read two integers from the user

    sum = a + b; // Calculate the sum of the two numbers
    std::cout << "The sum is: " << sum << std::endl; // Output the result

    return 0; // Indicate successful completion
}