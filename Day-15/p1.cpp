//1. Function Template for Swapping Values

#include <iostream>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swapValues(x, y);
    cout << "Swapped integers: " << x << ", " << y << endl;

    double m = 1.5, n = 2.5;
    swapValues(m, n);
    cout << "Swapped doubles: " << m << ", " << n << endl;

    return 0;
}