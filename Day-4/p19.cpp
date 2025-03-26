//do while loop

//1. Simple Menu System

#include <iostream>

int main() {
    int choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Option 1\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "You selected Option 1." << std::endl;
                break;
            case 2:
                std::cout << "You selected Option 2." << std::endl;
                break;
            case 3:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    } while (choice != 3); // Continue until the user chooses to exit

    return 0;
}