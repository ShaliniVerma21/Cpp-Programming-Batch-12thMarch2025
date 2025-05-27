/*
 Advantages of Templates

1. Code Reusability — Write once, use for any data type.

2. Clean Code — Avoids multiple versions of same function/class.

3. Generic Programming — Supports building libraries and generic containers like STL 
(Standard Template Library).
*/

#include <iostream>     // For input/output
using namespace std;

// Function Template with two types
template <class T1, class T2>
void display(T1 a, T2 b) {
    cout << "a = " << a << ", b = " << b << endl;
}

// Main function
int main() {
    display(10, 20.5);        // int and float
    display('A', "Apple");    // char and string
    display("Hello", 2025);   // string and int
    return 0;
}
