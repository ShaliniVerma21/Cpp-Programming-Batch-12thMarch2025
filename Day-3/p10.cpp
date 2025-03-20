//9. Pointer Operators
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a; // Pointer to a
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value at ptr: " << *ptr << endl; // Dereferencing pointer
    return 0;
}