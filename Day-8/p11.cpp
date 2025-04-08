//9. Reverse a String

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word = "hello";
    reverse(word.begin(), word.end());
    cout << "Reversed: " << word << endl;
    return 0;
}
