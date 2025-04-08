//7. Finding a Word in a String

#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "This is a sample sentence.";
    size_t pos = sentence.find("sample");

    if (pos != string::npos) {
        cout << "Word found at position: " << pos << endl;
    } else {
        cout << "Word not found." << endl;
    }
    return 0;
}
