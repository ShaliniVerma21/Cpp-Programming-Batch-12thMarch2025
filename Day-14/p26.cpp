/*
2. Class Templates
A class template allows you to define a class for multiple data types using one definition.

Syntax:

template <class T>
class ClassName {
    T variable;
public:
    ClassName(T val) {
        variable = val;
    }
    void display() {
        cout << "Value: " << variable << endl;
    }
};

*/

//Example: Class Template for a Simple Box

#include <iostream>
using namespace std;

template <class T>
class Box {
    T value;
public:
    Box(T val) {
        value = val;
    }
    void show() {
        cout << "Box contains: " << value << endl;
    }
};

int main() {
    Box<int> intBox(100);
    Box<float> floatBox(45.67);
    Box<string> stringBox("Hello");

    intBox.show();
    floatBox.show();
    stringBox.show();

    return 0;
}
