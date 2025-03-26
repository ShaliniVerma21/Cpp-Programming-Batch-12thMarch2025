//5. Basic Calculator

#include <iostream>

int main() {
    char operation;
    double num1, num2;

    do {
        std::cout << "Enter an operator (+, -, *, /) or 'q' to quit: ";
        std::cin >> operation;

        if (operation == 'q') {
            break; // Exit the loop if the user wants to quit
        }

        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        switch (operation) {
            case '+':
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case '-':
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            case '*':
                std::cout << "Result: " << num1 * num2 << std:: std::endl;
                break;
            case '/':
                if (num2 != 0) {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Division by zero!" << std::endl;
                }
                break;
            default:
                std::cout << "Invalid operator! Please try again." << std::endl;
                break;
        }
    } while (true); // Continue until the user chooses to quit

    std::cout << "Thank you for using the calculator!" << std::endl;
    return 0;
}