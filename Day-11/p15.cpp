/*
The this pointer is an implicit pointer available within non-static member functions of a class. 
It points to the object for which the member function is called. This allows you to access the object's 
members and differentiate between member variables and parameters with the same name.

Key Features of this Pointer:
1. It is a constant pointer that holds the address of the current object.
2. It can be used to return the current object from a member function (useful for method chaining).
3. It helps in resolving naming conflicts between member variables and parameters.
*/

#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int value) { // Constructor parameter
        this->value = value; // Using 'this' to differentiate
    }

    void display() {
        std::cout << "Value: " << this->value << std::endl; // Accessing member using 'this'
    }

    MyClass& setValue(int value) {
        this->value = value; // Using 'this' for assignment
        return *this; // Returning the current object
    }
};

int main() {
    MyClass obj(10);
    obj.display(); // Output: Value: 10
    obj.setValue(20).display(); // Method chaining
    return 0;
}