// 6. Substring from a String
//   - The substring() method returns a subset of characters from a string.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "Welcome to C++";
    string sub = sentence.substr(0, 7); // "Welcome"
    cout << "Substring: " << sub << endl;
    return 0;
}
