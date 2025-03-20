//1. Factorial of a Number (Using for Loop)
#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i; // Multiply factorial by i
        }
        cout << "Factorial of " << n << " = " << factorial << endl;
    }

    return 0;
}