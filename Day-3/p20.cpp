//3. Reverse a Number (Using do-while Loop)
#include <iostream>
using namespace std;

int main() {
    int n, reversedNumber = 0;

    cout << "Enter an integer: ";
    cin >> n;

    do {
        reversedNumber = reversedNumber * 10 + n % 10; // Build the reversed number
        n /= 10; // Remove the last digit
    } while (n != 0);

    cout << "Reversed Number = " << reversedNumber << endl;

    return 0;
}