//Example 3: Finding the Sum of Array Elements

#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an array of integers
    int values[4] = {1, 2, 3, 4};

    // Variable to hold the sum of the array elements
    int sum = 0;

    // Calculate the sum of the array elements
    for (int i = 0; i < 4; i++) {
        sum += values[i]; // Add each element to sum
    }

    // Print the total sum
    cout << "Total sum of array elements: " << sum << endl;

    return 0;
}
