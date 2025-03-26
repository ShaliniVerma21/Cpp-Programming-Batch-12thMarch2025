// jump statements (break, continue, and goto). 

//break

#include <iostream>

int main() {
    int number;

    std::cout << "Enter numbers (enter a negative number to stop):" << std::endl;

    while (true) {
        std::cout << "Number: ";
        std::cin >> number;

        if (number < 0) {
            std::cout << "Negative number entered. Exiting the loop." << std::endl;
            break; // Exit the loop if a negative number is entered
        }

        std::cout << "You entered: " << number << std::endl;
    }

    std::cout << "Program ended." << std::endl;
    return 0;
}