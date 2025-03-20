//7. Increment and Decrement Operators
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    cout << "Initial value: " << a <<"\n";
    //post increament (assign vaule then increase)
    cout << "Post-increment: " << a++ <<"\n"; // a is incremented after this line
    cout << "After post-increment: " << a <<"\n";
    //pre increament (increase then assign value)
    cout << "Pre-increment: " << ++a <<"\n";  // a is incremented before this line
    cout << "After pre-increment: " << a <<"\n";
    cout << "Post-decrement: " << a-- <<"\n"; // a is decremented after this line
    cout << "After post-decrement: " << a <<"\n";
    cout << "Pre-decrement: " << --a <<"\n";  // a is decremented before this line
    cout << "After pre-decrement: " << a << endl;
    return 0;
}