//5. Reverse a Number

#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Reversed number: " << reverseNumber(num) << endl;
    return 0;
}