//3. Password Validation

#include <iostream>
#include <string>

int main() {
    std::string password;
    const std::string correctPassword = "secure123";

    while (true) {
        std::cout << "Enter your password: ";
        std::cin >> password;

        if (password == correctPassword) {
            std::cout << "Access granted!" << std::endl;
            break; // Exit the loop
        } else {
            std::cout << "Incorrect password. Try again." << std::endl;
        }
    }

    return 0;
}