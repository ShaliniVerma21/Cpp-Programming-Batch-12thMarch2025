//Program 2: Stack empty check

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> letters;

    // Push characters
    letters.push('A');
    letters.push('B');

    // Check and display
    while(!letters.empty()) {
        cout << "Popped: " << letters.top() << endl;
        letters.pop();
    }
    return 0;
}
