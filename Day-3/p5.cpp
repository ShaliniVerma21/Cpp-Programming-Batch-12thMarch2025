//4. Bitwise Operators
#include <iostream>
using namespace std;

int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary
    cout << "a & b: " << (a & b) << endl; // Bitwise AND
    cout << "a | b: " << (a | b) << endl; // Bitwise OR
    cout << "a ^ b: " << (a ^ b) << endl; // Bitwise XOR
    cout << "~a: " << (~a) << endl;       // Bitwise NOT
    cout << "a << 1: " << (a << 1) << endl; // Left shift
    cout << "a >> 1: " << (a >> 1) << endl; // Right shift
    cout << "a << 5: " << (a << 5) << endl; // Left shift
    cout << "a >> 5: " << (a >> 5) << endl; // Right shift
    return 0;
}