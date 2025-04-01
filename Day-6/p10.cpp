//10. Sum of First N Natural Numbers

#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers: " << sumOfNaturalNumbers(n) << endl;
    return 0;
}