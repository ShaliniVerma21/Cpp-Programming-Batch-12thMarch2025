//Example 2: Modifying a Variable Using a Pointer

#include <iostream>
using namespace std;

int main() {
    int num = 20;          // Declare an integer variable
    int* ptr = &num;      // Pointer to the address of num

    // Output the original value of num
    cout << "Original value of num: " << num << endl; // Outputs: 20

    // Modify the value of num using the pointer
    *ptr = 30;            // Dereference ptr and change the value at that address

    // Output the modified value of num
    cout << "Modified value of num: " << num << endl; // Outputs: 30

    return 0;
}
