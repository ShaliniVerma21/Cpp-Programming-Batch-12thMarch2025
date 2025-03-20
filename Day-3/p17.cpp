//Example: Age Category
#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "Enter your age: ";
    cin >> age;

    if (age < 0) {
        cout << "Invalid age!" << endl; // Check for negative age
    } else {
        if (age <= 12) {
            cout << "You are a Child." << endl; // Age 0-12
        } else {
            if (age <= 19) {
                cout << "You are a Teenager." << endl; // Age 13-19
            } else {
                if (age <= 64) {
                    cout << "You are an Adult." << endl; // Age 20-64
                } else {
                    cout << "You are a Senior." << endl; // Age 65 and above
                }
            }
        }
    }

    return 0;
}