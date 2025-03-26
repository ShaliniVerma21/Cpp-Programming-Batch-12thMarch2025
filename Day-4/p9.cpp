//4. Fibonacci Series

#include <iostream>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";
    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        std::cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
    }
    std::cout << std::endl;
    return 0;
}