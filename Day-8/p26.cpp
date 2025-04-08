//Password Hider 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;

    cout << "Enter password: ";
    getline(cin, password);

    cout << "Password saved as: ";
    for (char c : password) {
        cout << "*";
    }

    cout << "\n(Original password was: \"" << password << "\")\n";
    return 0;
}
