/*
Math Functions :

C++ provides a variety of built-in math functions in the <cmath> library for performing mathematical 
operations.
*/

#include <iostream>
#include <cmath> // For built-in math functions
using namespace std;

// User-defined function to calculate the square of a number
double square(double num) {
    return num * num;
}

// User-defined function to calculate the cube of a number
double cube(double num) {
    return num * num * num;
}

// User-defined function to calculate the factorial of a number
unsigned long long factorial(int num) {
    if (num < 0) return 0; // Factorial is not defined for negative numbers
    if (num == 0 || num == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// User-defined function to calculate the sine of an angle in degrees
double sine(double degrees) {
    double radians = degrees * (M_PI / 180.0); // Convert degrees to radians
    return sin(radians);
}

// User-defined function to calculate the cosine of an angle in degrees
double cosine(double degrees) {
    double radians = degrees * (M_PI / 180.0); // Convert degrees to radians
    return cos(radians);
}

// User-defined function to calculate the tangent of an angle in degrees
double tangent(double degrees) {
    double radians = degrees * (M_PI / 180.0); // Convert degrees to radians
    return tan(radians);
}

int main() {
    double number = 16.0;

    // Using built-in functions
    double sqrtResult = sqrt(number);
    double powResult = pow(number, 2); // number raised to the power of 2
    double logResult = log(number); // Natural logarithm
    double expResult = exp(1); // e^1

    // Display results of built-in functions
    cout << "Using built-in functions:" << endl;
    cout << "Square root of " << number << " is " << sqrtResult << endl;
    cout << number << " raised to the power of 2 is " << powResult << endl;
    cout << "Natural logarithm of " << number << " is " << logResult << endl;
    cout << "e raised to the power of 1 is " << expResult << endl;

    // Using user-defined functions
    cout << "\nUsing user-defined functions:" << endl;
    cout << "Square of " << number << " is " << square(number) << endl;
    cout << "Cube of " << number << " is " << cube(number) << endl;
    cout << "Factorial of 5 is " << factorial(5) << endl;
    cout << "Sine of 30 degrees is " << sine(30) << endl;
    cout << "Cosine of 60 degrees is " << cosine(60) << endl;
    cout << "Tangent of 45 degrees is " << tangent(45) << endl;

    return 0;
}