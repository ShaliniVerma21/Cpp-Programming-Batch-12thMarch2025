//Example 6: Write and Read from File
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ofstream fout("data.txt");
    fout << "Learning File Handling!";
    fout.close();

    ifstream fin("data.txt");
    string line;
    getline(fin, line);
    cout << line;
    fin.close();
    return 0;
}
