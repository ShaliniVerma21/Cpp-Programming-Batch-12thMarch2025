//While loop

//1. Guess the Number Game

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    while (true) {
        std::cin >> guess;
        attempts++;

        if (guess > number) {
            std::cout << "Too high! Try again: ";
        } else if (guess < number) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << std::endl;
            break; // Exit the loop
        }
    }

    return 0;
}