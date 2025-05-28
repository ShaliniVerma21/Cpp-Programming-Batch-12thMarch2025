//6. Exception Handling

#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        cout << "Result: " << divide(10, 0) << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl; // Catching exception
    }
    return 0;
}