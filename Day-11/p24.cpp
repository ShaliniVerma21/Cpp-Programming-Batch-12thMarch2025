//5. Hybrid Inheritance(Example: Combination of multiple and hierarchical inheritance)

#include <iostream>
using namespace std;

// Base class 1
class A {
public:
    void displayA() {
        cout << "Class A" << endl;
    }
};

// Base class 2
class B {
public:
    void displayB() {
        cout << "Class B" << endl;
    }
};

// Derived class
class C : public A, public B {
public:
    void displayC() {
        cout << "Class C" << endl;
    }
};

int main() {
    C obj;
    obj.displayA(); // From A
    obj.displayB(); // From B
    obj.displayC(); // From C
    return 0;
}