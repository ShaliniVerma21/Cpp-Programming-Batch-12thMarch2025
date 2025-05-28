//7. Templates

#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(5, 10) << endl;
    cout << "Sum of doubles: " << add(5.5, 2.5) << endl;
    return 0;
}