// Program 2: Negative array size

#include <iostream>
using namespace std;

int main() {
    int size = -5;
    try {
        if (size < 0)
            throw "Array size cannot be negative!";
        int arr[size];  // For demo only
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }
    return 0;
}
