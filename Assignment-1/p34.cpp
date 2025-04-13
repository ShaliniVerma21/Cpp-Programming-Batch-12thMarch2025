//8. Implement a Simple Address Book

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    const int MAX_CONTACTS = 100;
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0, choice;

    do {
        cout << "\nAddress Book\n1. Add Contact\n2. View Contacts\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (contactCount < MAX_CONTACTS) {
                    cout << "Enter name: ";
                    cin >> contacts[contactCount].name;
                    cout << "Enter phone number: ";
                    cin >> contacts[contactCount].phone;
                    contactCount++;
                cout << "Contact added." << endl;
                } else {
                    cout << "Address book is full." << endl;
                }
                break;
            case 2:
                cout << "Contacts:\n";
                for (int i = 0; i < contactCount; i++) {
                    cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);
    return 0;
}