//Problem 5: Simple Mechanical Calculator

#include <iostream>
using namespace std;

class MechanicalCalculator {
public:
    float add(float a, float b) {
        return a + b;
    }
    float subtract(float a, float b) {
        return a - b;
    }
    float multiply(float a, float b) {
        return a * b;
    }
    float divide(float a, float b) {
        if (b != 0) return a / b;
        else {
            cout << "Division by zero error!" << endl;
            return 0;
        }
    }
};

int main() {
    MechanicalCalculator calc;
    float num1, num2;
    char operation;
    cout << "Enter two numbers and an operator (+, -, *, /): ";
    cin >> num1 >> num2 >> operation;

    switch (operation) {
        case '+': cout << "Result: " << calc.add(num1, num2); break;
        case '-': cout << "Result: " << calc.subtract(num1, num2); break;
        case '*': cout << "Result: " << calc.multiply(num1, num2); break;
        case '/': cout << "Result: " << calc.divide(num1, num2); break;
        default: cout << "Invalid operator!" << endl;
    }
    return 0;
}