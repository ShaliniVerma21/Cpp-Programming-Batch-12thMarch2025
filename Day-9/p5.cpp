//5. Dynamic Memory Allocation

#include <iostream>
using namespace std;

int main() {
    int* ptr = new int; // Dynamically allocate an integer
    *ptr = 50; // Assign value

    cout << "Value: " << *ptr << endl; // 50

    delete ptr; // Free the allocated memory
    return 0;
}