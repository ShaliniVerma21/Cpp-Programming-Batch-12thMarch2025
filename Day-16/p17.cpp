//Example 1: Creating and Initializing a Vector

#include <iostream>
#include <vector> // Include the vector library

int main() {
    // Create a vector of integers
    std::vector<int> numbers; // Declare an empty vector

    // Add elements to the vector
    numbers.push_back(10); // Add 10 to the vector
    numbers.push_back(20); // Add 20 to the vector
    numbers.push_back(30); // Add 30 to the vector

    // Print the elements of the vector
    std::cout << "Vector elements: ";
    for (int num : numbers) { // Loop through each element
        std::cout << num << " "; // Print the element
    }
    std::cout << std::endl; // New line

    return 0; // End of the program
}
