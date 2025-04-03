//6. Dynamic Array Allocation
#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    // Create a dynamic array
    int* dynamicArray = new int[size];

    // Input values
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> dynamicArray[i];
    }

    // Display values
    cout << "You entered:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": " << dynamicArray[i] << endl;
    }

    // Free the allocated memory
    delete[] dynamicArray;

    return 0;
}