/*
What is a Pointer?
----------------
A pointer is a variable that stores the memory address of another variable. 
Pointers are powerful because they allow you to directly access and manipulate memory.


Why Use Pointers?
----------------
1. Dynamic Memory Allocation: 
Pointers are used to allocate memory dynamically using new and delete.

2. Array and String Manipulation: 
Pointers can be used to navigate through arrays and strings.

3. Function Arguments: 
Pointers allow functions to modify variables passed to them.

4. Data Structures: 
Pointers are essential for creating complex data structures like linked lists, trees, etc.


1. Declaring Pointers
----------------
To declare a pointer, you use the * operator. 

For example:
----------------
int* ptr; // ptr is a pointer to an integer
char* str; // str is a pointer to a character


2. Initializing Pointers
----------------
You can initialize a pointer by assigning it the address of a variable using 
the & operator:

int var = 10;
int* ptr = &var; // ptr now holds the address of var

3. Dereferencing Pointers
----------------
To access the value stored at the address a pointer is pointing to, 
you use the * operator (this is called dereferencing):

int value = *ptr; // value is now 10, the value of var


4. Pointer Arithmetic
----------------
You can perform arithmetic operations on pointers. 
This is particularly useful when working with arrays:

int arr[] = {1, 2, 3, 4, 5};
int* ptr = arr; // points to the first element of the array

// Accessing elements using pointer arithmetic
int first = *ptr;      // 1
int second = *(ptr + 1); // 2
int third = *(ptr + 2); // 3


5. Pointers and Arrays
In C++, the name of an array acts as a pointer to its first element. For example:

int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr; // ptr points to arr[0]


6. Pointers to Pointers
You can have pointers that point to other pointers. 
This is called a pointer to a pointer:

int var = 20;
int* ptr = &var; // pointer to var
int** ptr2 = &ptr; // pointer to ptr


7. Dynamic Memory Allocation
You can allocate memory dynamically using new and deallocate it using delete:

int* ptr = new int; // dynamically allocate an integer
*ptr = 30;          // assign value

delete ptr;        // free the allocated memory

For arrays:

int* arr = new int[5]; // dynamically allocate an array of 5 integers
delete[] arr;          // free the allocated array


8. Null Pointers
----------------
A null pointer is a pointer that does not point to any valid memory location. 
You can initialize a pointer to null using nullptr (C++11 and later):

int* ptr = nullptr; // ptr is a null pointer

*/

//1. Basic Pointer Declaration and Initialization

#include <iostream>
using namespace std;

int main() {
    int var = 42;
    int* ptr = &var; // Pointer to var

    cout << "Value of var: " << var << endl; // 42
    cout << "Address of var: " << &var << endl; // Address of var
    cout << "Value of ptr: " << ptr << endl; // Address of var
    cout << "Value pointed by ptr: " << *ptr << endl; // 42

    return 0;
}