//Name Reverser

#include <iostream>
#include <string>
using namespace std;

int main() {
    // This program reverses the entered name
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Reversed Name: ";
    for (int i = name.length() - 1; i >= 0; i--) {
        cout << name[i];
    }

    cout << endl;
    return 0;
}
