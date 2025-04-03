/*
Dynamic Arrays :

Dynamic arrays are arrays that can change size at runtime. They are also known as vectors or lists.
Dynamic arrays are useful when you don't know the size of the array. If you need an array whose size can
be determined at runtime, you can use dynamic memory allocation:

int* dynamicArray = new int[size]; // Allocates an array of 'size' integers

// Don't forget to free the memory when done
delete[] dynamicArray;

 */

#include <iostream>
using namespace std;

int main()
{
    int size;

    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> size;

    // Create a dynamic array
    int *dynamicArray = new int[size];

    // Input values into the dynamic array
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> dynamicArray[i];
    }

    // Display the values
    cout << "\nYou entered:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << dynamicArray[i] << endl;
    }

    // Free the allocated memory
    delete[] dynamicArray;

    return 0;
}