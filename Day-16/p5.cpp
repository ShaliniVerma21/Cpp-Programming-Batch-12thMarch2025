//Example 1: Declaring and Initializing an Array

#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an array of integers with 5 elements
    int numbers[5] = {10, 20, 30, 40, 50};

    // Print the elements of the array
    for (int i = 0; i < 5; i++) {
        cout << "Element at index " << i << ": " << numbers[i] << endl;
    }

    return 0;
}
