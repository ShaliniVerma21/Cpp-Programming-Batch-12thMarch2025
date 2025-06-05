// Example 5: File stream - reading

#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream fin("stream.txt");
    std::string content;
    getline(fin, content);
    std::cout << content;
    fin.close();
    return 0;
}
