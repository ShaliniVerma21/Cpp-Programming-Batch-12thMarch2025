//Example 7: Use of Pointer

#include <iostream>
using namespace std;
int main() {
    int a = 100;
    int *ptr = &a;
    cout << "Value: " << *ptr << "\nAddress: " << ptr;
    return 0;
}
