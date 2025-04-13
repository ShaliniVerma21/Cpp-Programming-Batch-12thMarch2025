//6.  Implement a Simple Text-Based Adventure Game

#include <iostream>
#include <string>
using namespace std;

int main() {
    string choice;
    cout << "Welcome to the Adventure Game!\n";
    cout << "You are in a forest. You can go left or right.\n";
    cout << "Type 'left' to go left or 'right' to go right: ";
    cin >> choice;

    if (choice == "left") {
        cout << "You encounter a wild animal! You can run or fight.\n";
        cout << "Type 'run' to escape or 'fight' to confront it: ";
        cin >> choice;
        if (choice == "run") {
            cout << "You successfully escaped!\n";
        } else {
            cout << "You fought bravely but lost the battle.\n";
        }
    } else if (choice == "right") {
        cout << "You find a treasure chest! You can open it or leave it.\n";
        cout << "Type 'open' to open the chest or 'leave' to walk away: ";
        cin >> choice;
        if (choice == "open") {
            cout << "You found gold and jewels! You are rich!\n";
        } else {
            cout << "You chose to leave the treasure behind.\n";
        }
    } else {
        cout << "Invalid choice. Game over.\n";
    }
    return 0;
}