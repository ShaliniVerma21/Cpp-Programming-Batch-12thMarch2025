//2. Pointer Arithmetic

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // Pointer to the first element of the array

    for (int i = 0; i < 5; i++) {
        cout << "Value at arr[" << i << "] = " << *(ptr + i) << endl; // Accessing using pointer arithmetic
    }

    return 0;
}