//Example 3: Pointer Arithmetic
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Declare an array of integers
    int* ptr = arr;             // Pointer to the first element of the array

    // Output the elements of the array using pointer arithmetic
    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " "; // Access each element using pointer arithmetic
    }
    cout << endl; // New line for better readability

    return 0;
}
