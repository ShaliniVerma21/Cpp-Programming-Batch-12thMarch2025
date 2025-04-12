//9. Null Pointer

#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr; // Initialize a null pointer

    if (ptr == nullptr) {
        cout << "Pointer is null, cannot dereference." << endl; // Check if pointer is null
    } else {
        cout << "Pointer value: " << *ptr << endl; // This line won't execute
    }

    return 0;
}