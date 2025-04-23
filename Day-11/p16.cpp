/*
The static keyword in C++ can be used in several contexts, including static data members, static member 
functions, and static local variables.

Static Data Members:

1. Static data members belong to the class rather than any specific object. They are shared among all 
instances of the class.
2. They can be accessed using the class name or through an object.
*/

#include <iostream>

class MyClass {
public:
    static int count; // Declaration of static member

    MyClass() {
        count++; // Increment count for each object created
    }
};

// Definition of static member outside the class
int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    std::cout << "Number of objects created: " << MyClass::count << std::endl; // Output: 2
    return 0;
}