//5. Simple Robot Command Interface

#include <iostream>
#include <string>

int main() {
    std::string command;

    std::cout << "Enter a command for the robot (move, stop, turn left, turn right): ";
    std::cin >> command;

    if (command == "move") {
        std::cout << "Robot is moving forward." << std::endl;
    } else if (command == "stop") {
        std::cout << "Robot has stopped." << std::endl;
    } else if (command == "turn left") {
        std::cout << "Robot is turning left." << std::endl;
    } else if (command == "turn right") {
        std::cout << "Robot is turning right." << std::endl;
    } else {
        std::cout << "Invalid command!" << std::endl;
    }

    return 0;
}