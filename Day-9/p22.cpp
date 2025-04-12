//8. Counting Vowels in a String Using Pointers

#include <iostream>
using namespace std;

int countVowels(const char* str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    const char* myString = "Hello, World!";
    cout << "Number of vowels: " << countVowels(myString) << endl;
    return 0;
}