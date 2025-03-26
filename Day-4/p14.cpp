//9. Calculate Average of Numbers

#include <iostream>

int main() {
    int n;
    double sum = 0.0;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        double num;
        std::cout << "Enter number " << i << ": ";
        std::cin >> num;
        sum += num;
    }

    std::cout << "Average = " << sum / n << std::endl;
    return 0;
}