//Word Counter in a Sentence
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    int count = 1;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for (char c : sentence) {
        if (c == ' ') count++;
    }

    cout << "Number of words: " << count << endl;
    return 0;
}
