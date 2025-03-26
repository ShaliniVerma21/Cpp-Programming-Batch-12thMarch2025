//1. Sum of First N Natural Numbers
#include <iostream>

int main() {
    int n, sum = 0;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "Sum of first " << n << " natural numbers is: " << sum << std::endl;
    return 0;
}