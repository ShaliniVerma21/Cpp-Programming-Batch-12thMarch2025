//3. Pointers and Arrays

#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    int* ptr = arr; // Pointer to the first element of the array

    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << ptr[i] << endl; // Accessing array elements using pointer
    }

    return 0;
}