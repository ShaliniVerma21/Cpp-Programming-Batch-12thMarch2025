// Example 4: Factorial using Function

#include <iostream>
using namespace std;
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Factorial = " << factorial(num);
    return 0;
}
