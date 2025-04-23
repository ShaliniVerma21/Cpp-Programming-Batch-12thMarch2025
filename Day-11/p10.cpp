/*
Copy Constructor: 

A constructor that creates a new object as a copy of an existing object. 
It takes a reference to an object of the same class as a parameter.
*/
#include <iostream>
class MyClass {
    public:
        int value;
    
        MyClass(int v) : value(v) {} // Parameterized constructor
    
        // Copy constructor
        MyClass(const MyClass &obj) {
            value = obj.value;
            std::cout << "Copy constructor called!" << std::endl;
        }
    };
    
    int main() {
        MyClass obj1(10); // Calls parameterized constructor
        MyClass obj2 = obj1; // Calls copy constructor
        std::cout << "Value of obj2: " << obj2.value << std::endl;
        return 0;
    }