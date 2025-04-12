//7. Passing Pointers to Functions

#include <iostream>
using namespace std;

void increment(int* ptr) {
    (*ptr)++; // Increment the value pointed by ptr
}

int main() {
    int var = 5;
    cout << "Before increment: " << var << endl; // 5
    increment(&var); // Pass the address of var
    cout << "After increment: " << var << endl; // 6

    return 0;
}