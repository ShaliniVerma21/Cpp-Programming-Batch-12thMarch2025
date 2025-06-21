//Example 2: Polymorphism with Function Overloading

#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "Sum of 2 and 3 (int): " << add(2, 3) << endl; // Calls int version
    cout << "Sum of 2.5 and 3.5 (double): " << add(2.5, 3.5) << endl; // Calls double version
    cout << "Sum of 1, 2, and 3 (int): " << add(1, 2, 3) << endl; // Calls three int version

    return 0;
}
