//10. Comma Operator
// The comma operator is a binary operator that evaluates both expressions on 
// either side of the comma and returns the value of the second expression.

#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c;
    c = (a += 1, b += 2, a + b); // Comma operator
    cout << "Value of c: " << c << endl; // c will be 6 (2 + 4)
    return 0;
}