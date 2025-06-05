// Example 2: Read from file

#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream file("example.txt");
    std::string text;
    getline(file, text);
    std::cout << text;
    file.close();
    return 0;
}
