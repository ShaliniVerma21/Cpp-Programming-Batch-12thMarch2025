// Example 4: Check if file is open

#include <iostream>
#include <fstream>
int main() {
    std::ifstream file("example.txt");
    if (file.is_open())
        std::cout << "File opened successfully.";
    else
        std::cout << "File not found.";
    file.close();
    return 0;
}
