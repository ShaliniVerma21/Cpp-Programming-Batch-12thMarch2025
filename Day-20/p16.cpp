//10 miscellaneous C++ examples

//Example 1: Check Prime Number

#include <iostream>
using namespace std;
int main() {
    int num, flag = 0;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }
    if (num <= 1)
        cout << "Not a prime number.";
    else if (flag == 0)
        cout << "Prime number.";
    else
        cout << "Not a prime number.";
    return 0;
}
