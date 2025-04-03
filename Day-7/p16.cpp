//4. Counting Vowels in a String

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int maxLength = 100;
    char str[maxLength];
    int vowelCount = 0;

    // Input string
    cout << "Enter a string: ";
    cin.getline(str, maxLength);

    // Count vowels
    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;

    return 0;
}