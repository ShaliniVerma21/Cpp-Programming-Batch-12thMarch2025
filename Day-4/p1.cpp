//if-else

//vote_eligibility

#include <iostream>

int main() {
    int age;

    // Ask the user for their age
    std::cout << "Please enter your age: ";
    std::cin >> age;

    // Check if the user is eligible to vote
    if (age >= 18) {
        std::cout << "You are eligible to vote!" << std::endl;
    } else {
        std::cout << "You are not eligible to vote yet." << std::endl;
    }

    return 0;
}