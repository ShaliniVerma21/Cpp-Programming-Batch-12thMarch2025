//8. Function Returning a Pointer

#include <iostream>
using namespace std;

int* createArray(int size) {
    return new int[size]; // Return a pointer to a dynamically allocated array
}

int main() {
    int size = 3;
    int* arr = createArray(size); // Get the pointer to the array

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Assign values
    }

    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl; // Print values
    }

    delete[] arr; // Free the allocated array
    return 0;
}