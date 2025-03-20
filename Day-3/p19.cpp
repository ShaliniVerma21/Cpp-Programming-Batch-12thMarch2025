//2. Sum of Natural Numbers (Using while Loop)
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, i = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    while (i <= n) {
        sum += i; // Add i to sum
        i++;      // Increment i
    }

    cout << "Sum of first " << n << " natural numbers = " << sum << endl;

    return 0;
}