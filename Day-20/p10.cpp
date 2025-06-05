//Example 5: Read file line by line

#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream file("example.txt");
    std::string line;
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
    return 0;
}
