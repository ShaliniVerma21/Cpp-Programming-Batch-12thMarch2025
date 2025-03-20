//8. Sizeof Operator
#include <iostream>
using namespace std;

int main() {
    int a;
    double b;
    char c;
    bool isStudent=true;
    cout << "Size of int: " << sizeof(a) << " bytes" << endl;
    cout << "Size of double: " << sizeof(b) << " bytes" << endl;
    cout << "Size of char: " << sizeof(c) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(isStudent) << " bytes" << endl;
    return 0;
}