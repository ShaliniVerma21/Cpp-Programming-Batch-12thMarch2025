//Problem 16: Simple Language Translator

#include <iostream>
#include <string>
using namespace std;

void translateToSpanish(string word) {
    if (word == "Hello") {
        cout << "Hola" << endl;
    } else if (word == "Goodbye") {
        cout << "Adiós" << endl;
    } else {
        cout << "Translation not available." << endl;
    }
}

int main() {
    string word;
    cout << "Enter a word in English: ";
    cin >> word;
    translateToSpanish(word);
    return 0;
}