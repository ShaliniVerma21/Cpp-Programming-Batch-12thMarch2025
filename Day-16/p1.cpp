//Doubt Session

/*
1. Pointer
2. Array
3. Pure virtual function 
4. Scoped enumeration 
5. Polymorphism 
6. Vector 
7. Patterns
8. This keyword
*/

//Example 1: Basic Pointer Declaration and Initialization

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
