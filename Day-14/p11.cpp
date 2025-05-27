//Program 4: Using catch(...) for unknown exceptions

#include <iostream>
using namespace std;

int main() {
    try {
        throw 3.14; // throwing a double
    }
    catch (...) {
        cout << "Caught an unknown exception!" << endl;
    }
    return 0;
}
