//3. Logical Operators
#include <iostream>
using namespace std;

int main() {
    bool x = true, y = false;
    cout << "x && y: " << (x && y) << endl; // Logical AND
    cout << "x || y: " << (x || y) << endl; // Logical OR
    cout << "!x: " << (!x) << endl;         // Logical NOT
    return 0;
}