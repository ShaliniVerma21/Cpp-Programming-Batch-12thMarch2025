//Example 2: Accessing Elements in a Vector

#include <iostream>
#include <vector> // Include the vector library

int main() {
    // Create and initialize a vector with values
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Access and print specific elements
    std::cout << "First element: " << numbers[0] << std::endl; // Access the first element
    std::cout << "Second element: " << numbers.at(1) << std::endl; // Access the second element using at()

    // Modify an element
    numbers[2] = 10; // Change the third element to 10
    std::cout << "Modified third element: " << numbers[2] << std::endl; // Print the modified element

    return 0; // End of the program
}
