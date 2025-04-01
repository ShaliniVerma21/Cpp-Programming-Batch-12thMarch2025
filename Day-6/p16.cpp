/*
There are two types of functions in C programming:

1. Library Functions: 
Library functions are the functions, which are declared in the C++ header files, 
such as ceil(x), cos(x), exp(x), etc.

ceil(x): It returns the smallest integer greater than or equal to x
cos(x): It computes the cosine of x
exp(x): The function exp(x) calculates the value of e when it is powered by x.


2. User-defined functions: 
User-defined functions are the functions, which are created by the C++ programmer 
so that the developer can use them many times. It reduces the complexity of a big 
program and optimizes the code.
*/

//1. Using <cmath> for Mathematical Functions

#include <iostream>
#include <cmath> // For mathematical functions
using namespace std;

int main() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Square root: " << sqrt(num) << endl;
    cout << "Power (num^2): " << pow(num, 2) << endl;
    cout << "Sine: " << sin(num) << endl;
    cout << "Cosine: " << cos(num) << endl;
    cout << "Tangent: " << tan(num) << endl;

    return 0;
}