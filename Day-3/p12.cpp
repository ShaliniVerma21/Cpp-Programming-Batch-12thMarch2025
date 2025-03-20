//1. Even or Odd Number
#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (number % 2 == 0) {
        cout << number << " is even." << endl;
    } 
    else {
        cout << number << " is odd." << endl;
    }

    return 0;
}