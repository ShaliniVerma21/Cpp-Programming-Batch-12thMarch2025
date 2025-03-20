//5. Assignment Operators
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    a += 5; // a = a + 5
    cout << "After += : " << a << endl;
    a -= 3; // a = a - 3
    cout << "After -= : " << a << endl;
    a *= 2; // a = a * 2
    cout << "After *= : " << a << endl;
    a /= 2; // a = a / 2
    cout << "After /= : " << a << endl;
    a %= 3; // a = a % 3
    cout << "After %= : " << a << endl;
    return 0;
}