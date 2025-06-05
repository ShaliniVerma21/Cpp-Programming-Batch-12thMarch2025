// Example 4: File stream - writing

#include <fstream>
int main() {
    std::ofstream fout("stream.txt");
    fout << "Stream to file!";
    fout.close();
    return 0;
}
