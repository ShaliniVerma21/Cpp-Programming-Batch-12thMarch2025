//6. Dynamic Array Allocation

#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size]; // Dynamically allocate an array

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10; // Assign values
    }

    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl; // Print values
    }

    delete[] arr; // Free the allocated array
    return 0;
}