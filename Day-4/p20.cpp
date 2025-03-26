//2. Password Entry

#include <iostream>
#include <string>

int main() {
    std::string password;
    const std::string correctPassword = "mypassword";

    do {
        std::cout << "Enter your password: ";
        std::cin >> password;

        if (password != correctPassword) {
            std::cout << "Incorrect password. Try again." << std::endl;
        }
    } while (password != correctPassword); // Repeat until the correct password is entered

    std::cout << "Access granted!" << std::endl;
    return 0;
}