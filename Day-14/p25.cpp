/*
Templates in C++ allow us to write generic and reusable code. Instead of writing the same function or 
class for different data types (int, float, etc.), we can use templates.

There are two types of templates: Function Templates & Class Templates

1. Function Templates
A function template allows you to create a single function to work with different data types.

Syntax:

template <typename T>
T functionName(T a, T b) {
    // code
}

template <typename T> — T is a placeholder for a data type.
You can use T like a normal data type inside the function.
*/

//Example: Function Template to Find Maximum

#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 3.5 and 2.5: " << findMax(3.5, 2.5) << endl;
    cout << "Max of 'A' and 'Z': " << findMax('A', 'Z') << endl;
    return 0;
}
