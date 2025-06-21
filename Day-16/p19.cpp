//Example 3: Iterating Over a Vector

#include <iostream>
#include <vector> // Include the vector library

int main() {
    // Create and initialize a vector with values
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};

    // Iterate over the vector using a range-based for loop
    std::cout << "Fruits in the vector: ";
    for (const std::string& fruit : fruits) { // Loop through each fruit
        std::cout << fruit << " "; // Print the fruit
    }
    std::cout << std::endl; // New line

    // Get the size of the vector
    std::cout << "Number of fruits: " << fruits.size() << std::endl; // Print the size of the vector

    return 0; // End of the program
}
