// 7. Count Vowels in a String
#include <iostream>
#include <string>

int main() {
    std::string str;
    int count = 0;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    std::cout << "Number of vowels: " << count << std::endl;
    return 0;
}