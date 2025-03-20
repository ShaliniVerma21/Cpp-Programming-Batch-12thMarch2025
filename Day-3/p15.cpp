//4. Simple Calculator
#include <iostream>
using namespace std;

int main() {
    char operation;
    float num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        cout << "Result: " << (num1 + num2) << endl;
    } else if (operation == '-') {
        cout << "Result: " << (num1 - num2) << endl;
    } else if (operation == '*') {
        cout << "Result: " << (num1 * num2) << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            cout << "Result: " << (num1 / num2) << endl;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
    } else {
        cout << "Invalid operation!" << endl;
    }

    return 0;
}