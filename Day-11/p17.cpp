/*
Static Member Functions:
1. Static member functions can only access static data members and cannot access non-static members directly.
2. They can be called without creating an object of the class.
*/

#include <iostream>

class MyClass {
public:
    static int count;

    MyClass() {
        count++;
    }

    static void displayCount() { // Static member function
        std::cout << "Count: " << count << std::endl;
    }
};

int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass::displayCount(); // Calling static member function
    return 0;
}