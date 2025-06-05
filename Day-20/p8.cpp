// Example 3: Append to file

#include <fstream>
int main() {
    std::ofstream file("example.txt", std::ios::app);
    file << "\nAppended line!";
    file.close();
    return 0;
}
