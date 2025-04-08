//Login System

#include <iostream>
#include <string>
using namespace std;

int main() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Simple login check
    //window + . for emojies
    if (username == "admin" && password == "1234") {
        cout << "\nLogin Successful! 🎉\n";
    } else {
        cout << "\nLogin Failed. ❌\n";
    }

    return 0;
}
