// Example 10: Count Vowels in a String

#include <iostream>
using namespace std;
int main() {
    string str = "Hello World";
    int count = 0;
    for (char c : str) {
        if (c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'||
            c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U') {
            count++;
        }
    }
    cout << "Number of vowels: " << count;
    return 0;
}
