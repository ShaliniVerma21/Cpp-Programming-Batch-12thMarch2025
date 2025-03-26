// nested if-else

// Driver's License Eligibility Checker

#include <iostream>

int main()
{
    int age;
    bool passedTest;

    // Ask the user for their age
    std::cout << "Please enter your age: ";
    std::cin >> age;

    // Check if the user is old enough to apply for a driver's license
    if (age >= 16)
    {
        std::cout << "You are old enough to apply for a driver's license." << std::endl;

        // Ask if the user has passed the driving test
        std::cout << "Have you passed the driving test? (1 for Yes, 0 for No): ";
        std::cin >> passedTest;

        // Nested if-else to check if the user can get a license
        if (passedTest)
        {
            std::cout << "Congratulations! You are eligible for a driver's license."
                      << std::endl;
        }
        else
        {
            std::cout << "You need to pass the driving test to get a driver's license."
                      << std::endl;
        }
    }
    else
    {
        std::cout << "You are not old enough to apply for a driver's license." << std::endl;
    }

    return 0;
}