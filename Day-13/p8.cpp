/*
Abstraction is a fundamental concept in object-oriented programming (OOP) that focuses on hiding the complex 
implementation details and showing only the essential features of an object. In C++, abstraction allows you 
to define interfaces and abstract classes that can be used to create more complex systems while keeping the 
implementation hidden.

Purpose of Abstraction -->

1. Simplification: Reduces complexity by hiding unnecessary details.
2. Code Reusability: Allows for the creation of reusable components.
3. Maintainability: Makes it easier to manage and update code.
4. Flexibility: Enables the use of different implementations without changing the interface.

Types of Abstraction -->

1. Data Abstraction: Hiding the details of data representation and exposing only the necessary parts.
2. Control Abstraction: Hiding the details of control flow and exposing only the necessary operations.
*/

/*
1. Abstract Classes and Pure Virtual Functions-->

An abstract class is a class that cannot be instantiated and usually contains at least one pure virtual 
function. A pure virtual function is declared by assigning 0 in its declaration.
*/

#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0; // No implementation, must be overridden
};

class Circle : public Shape {
public:
    void draw() override { // Override the pure virtual function
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override { // Override the pure virtual function
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle(); // Create a Circle object
    Shape* shape2 = new Square(); // Create a Square object

    shape1->draw(); // Calls Circle's draw()
    shape2->draw(); // Calls Square's draw()

    delete shape1; // Clean up
    delete shape2; // Clean up
    return 0;
}