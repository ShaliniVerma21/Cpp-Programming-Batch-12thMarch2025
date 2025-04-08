// 4. Accessing Characters in a String

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "Hello";
    cout << "First character: " << word[0] << endl;
    cout << "Last character: " << word[word.length() - 1] << endl;
    return 0;
}

