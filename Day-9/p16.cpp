//2. Finding the Length of a String Using Pointers

#include <iostream>
using namespace std;

int stringLength(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str; // Length of the string
}

int main() {
    const char* myString = "Hello, World!";
    cout << "Length of the string: " << stringLength(myString) << endl;
    return 0;
}