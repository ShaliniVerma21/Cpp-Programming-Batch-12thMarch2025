/*
In C++, an array is a collection of elements of the same type, stored in contiguous 
memory locations. Arrays are used to store multiple values in a single variable, 
instead of declaring separate variables for each value. 

1. Declaring Arrays : 

int myArray[5]; // Declares an array of 5 integers

2. Initializing Arrays : 

int myArray[5] = {1, 2, 3, 4, 5}; // Initializes the array with values

3. Accessing Array Elements: 

int firstElement = myArray[0]; // Accesses the first element
myArray[1] = 10; // Changes the second element to 10

4. Looping Through Arrays

for (int i = 0; i < 5; i++) {
    std::cout << myArray[i] << " "; // Prints each element
}


C++ also supports multidimensional arrays, such as 2D arrays. 
Here’s how to declare and initialize a 2D array:

int my2DArray[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

You can access elements in a 2D array using two indices:
int value = my2DArray[1][2]; // Accesses the element at row 1, column 2 (value is 7)

*/

#include <iostream>

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};

    // Print the array elements
    for (int i = 0; i < 5; i++) {
        std::cout << "Element at index " << i << ": " << myArray[i] << std::endl;
    }

    // Modify an element
    myArray[2] = 10;

    // Print the modified array
    std::cout << "After modification:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Element at index " << i << ": " << myArray[i] << std::endl;
    }

    return 0;
}