//continue

#include <iostream>

int main() {
    std::cout << "Even numbers from 1 to 10:" << std::endl;

    for (int i = 1; i <= 10; ++i) {
        if (i % 2 != 0) {
            continue; // Skip the current iteration if the number is odd
        }

        std::cout << i << " "; // Print the even number
    }

    std::cout << std::endl;
    return 0;
}