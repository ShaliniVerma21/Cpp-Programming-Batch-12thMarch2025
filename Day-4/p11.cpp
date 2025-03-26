//6. Reverse a Number
#include <iostream>

int main() {
    int n, reversedNumber = 0;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    for (; n != 0; n /= 10) {
        reversedNumber = reversedNumber * 10 + n % 10;
    }

    std::cout << "Reversed Number: " << reversedNumber 
    << std::endl;
    return 0;
}