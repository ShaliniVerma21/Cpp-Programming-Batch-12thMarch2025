// Program 3: Multiple catch blocks

#include <iostream>
using namespace std;

int main() {
    try {
        int age = 15;
        if (age < 18)
            throw age;
    }
    catch (int x) {
        cout << "Exception: Age " << x << " is too young to vote." << endl;
    }
    catch (...) {
        cout << "Unknown exception occurred!" << endl;
    }
    return 0;
}
