//4. Simple Voting System

#include <iostream>

int main() {
    int vote;
    int votesA = 0, votesB = 0;

    do {
        std::cout << "Vote for your favorite candidate:\n";
        std::cout << "1. Candidate A\n";
        std::cout << "2. Candidate B\n";
        std::cout << "3. Exit voting\n";
        std::cout << "Enter your choice: ";
        std::cin >> vote;

        switch (vote) {
            case 1:
                votesA++;
                std::cout << "You voted for Candidate A." << std::endl;
                break;
            case 2:
                votesB++;
                std::cout << "You voted for Candidate B." << std::endl;
                break;
            case 3:
                std::cout << "Exiting voting." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    } while (vote != 3); // Continue until the user chooses to exit

    std::cout << "Total votes for Candidate A: " << votesA << std::endl;
    std::cout << "Total votes for Candidate B: " << votesB << std::endl;

    return 0;
}