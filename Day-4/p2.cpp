//if-else-if (ladder)

//Grade Calculator

#include <iostream>

int main() {
    int score;

    // Ask the user for their score
    std::cout << "Please enter your score (0-100): ";
    std::cin >> score;

    // Determine the grade using if-else-if ladder
    if (score >= 90 && score <= 100) {
        std::cout << "Grade: A" << std::endl;
    } else if (score >= 80 && score < 90) {
        std::cout << "Grade: B" << std::endl;
    } else if (score >= 70 && score < 80) {
        std::cout << "Grade: C" << std::endl;
    } else if (score >= 60 && score < 70) {
        std::cout << "Grade: D" << std::endl;
    } else if (score >= 0 && score < 60) {
        std::cout << "Grade: F" << std::endl;
    } else {
        std::cout << "Invalid score! Please enter a score between 0 and 100." << std::endl;
    }

    return 0;
}