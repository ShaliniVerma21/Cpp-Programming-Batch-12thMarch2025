//Operator Overloading Example:

#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float imag;

    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, result;
    c1.real = 1.5; c1.imag = 2.5;
    c2.real = 3.5; c2.imag = 4.5;

    result = c1 + c2; // Calls operator+
    cout << "Result: " << result.real << " + " << result.imag << "i" << endl;
    return 0;
}