//4. Pointers to Pointers

#include <iostream>
using namespace std;

int main() {
    int var = 100;
    int* ptr = &var; // Pointer to var
    int** ptr2 = &ptr; // Pointer to pointer

    cout << "Value of var: " << var << endl; // 100
    cout << "Value pointed by ptr: " << *ptr << endl; // 100
    cout << "Value pointed by ptr2: " << **ptr2 << endl; // 100

    return 0;
}