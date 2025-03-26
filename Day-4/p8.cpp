//3. Finding Prime Numbers

#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    std::cout << "Prime numbers up to " << n << " are: ";
    for (int num = 2; num <= n; ++num) {
        bool isPrime = true;
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}