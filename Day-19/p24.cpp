//24. Event RSVP System

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>  // for exception handling
using namespace std;

// ======================= ABSTRACT BASE CLASS =====================
class AbstractGuest {
public:
    virtual void display() const = 0; // Pure virtual function (abstraction)
    virtual ~AbstractGuest() {}       // Virtual destructor
};

// ======================= GUEST CLASS (ENCAPSULATION) =====================
class Guest : public AbstractGuest {
protected:
    string name;
    string email;
    int numOfGuests;
    string status;

public:
    // Constructor
    Guest(string n, string e, int g, string s)
        : name(n), email(e), numOfGuests(g), status(s) {}

    // Setters
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setGuests(int g) { numOfGuests = g; }
    void setStatus(string s) { status = s; }

    // Getters
    string getName() const { return name; }

    // Polymorphic function
    virtual void display() const override {
        cout << "\n\tName:\t\t" << name
             << "\n\tEmail:\t\t" << email
             << "\n\tNo. of Guests:\t" << numOfGuests
             << "\n\tRSVP Status:\t" << status << "\n";
    }

    virtual ~Guest() {}
};

// ======================= VIP GUEST CLASS (INHERITANCE & POLYMORPHISM) =====================
class VIPGuest : public Guest {
    string specialNote;

public:
    VIPGuest(string n, string e, int g, string s, string note)
        : Guest(n, e, g, s), specialNote(note) {}

    void display() const override {
        Guest::display();
        cout << "\tNote:\t\t" << specialNote << "\n";
    }
};

// ======================= GLOBAL VECTOR (STL + POINTERS) =====================
vector<AbstractGuest*> guestList; // pointer for polymorphism

// ======================= FUNCTION DECLARATIONS =====================
void showMenu();
void addGuest();
void viewGuests();
void updateGuest();
void deleteGuest();
void cleanup();

// ======================= MAIN FUNCTION =====================
int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // to handle newline in buffer

        try {
            switch (choice) {
                case 1: addGuest(); break;
                case 2: viewGuests(); break;
                case 3: updateGuest(); break;
                case 4: deleteGuest(); break;
                case 5:
                    cout << "\nThank you for using the RSVP System!\n";
                    break;
                default:
                    throw runtime_error("Invalid choice! Please select from menu.");
            }
        } catch (const exception &e) {
            cout << "\n\tError: " << e.what() << "\n";
        }

    } while (choice != 5);

    cleanup(); // free memory
    return 0;
}

// ======================= MENU FUNCTION =====================
void showMenu() {
    cout << "\n\n\t========== Event RSVP System ==========\n";
    cout << "\t1. Add Guest RSVP\n";
    cout << "\t2. View All RSVPs\n";
    cout << "\t3. Update RSVP\n";
    cout << "\t4. Delete RSVP\n";
    cout << "\t5. Exit\n";
    cout << "\t=======================================\n";
}

// ======================= ADD GUEST FUNCTION =====================
void addGuest() {
    string name, email, status, note, vipOption;
    int guests;

    cout << "\n\tEnter Guest Name: ";
    getline(cin, name);
    cout << "\tEnter Email: ";
    getline(cin, email);
    cout << "\tEnter Number of Guests: ";
    cin >> guests;
    cin.ignore();
    cout << "\tRSVP Status (Yes/No/Maybe): ";
    getline(cin, status);

    cout << "\tIs this a VIP guest? (yes/no): ";
    getline(cin, vipOption);

    if (vipOption == "yes") {
        cout << "\tEnter Special Note: ";
        getline(cin, note);
        guestList.push_back(new VIPGuest(name, email, guests, status, note));
    } else {
        guestList.push_back(new Guest(name, email, guests, status));
    }

    cout << "\n\t✔ Guest added successfully!\n";
}

// ======================= VIEW GUEST FUNCTION =====================
void viewGuests() {
    if (guestList.empty()) {
        cout << "\n\tNo RSVP records found!\n";
        return;
    }

    cout << "\n\t--- RSVP LIST ---\n";
    for (size_t i = 0; i < guestList.size(); ++i) {
        cout << "\n\tID: " << i + 1;
        guestList[i]->display();
    }
}

// ======================= UPDATE GUEST FUNCTION =====================
void updateGuest() {
    int id;
    viewGuests();

    cout << "\n\tEnter ID to update: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > guestList.size()) {
        throw out_of_range("Invalid ID selected.");
    }

    Guest* g = dynamic_cast<Guest*>(guestList[id - 1]);
    if (!g) throw runtime_error("Cannot update this guest type.");

    string name, email, status;
    int guests;

    cout << "\tEnter New Name: ";
    getline(cin, name);
    cout << "\tEnter New Email: ";
    getline(cin, email);
    cout << "\tEnter New Number of Guests: ";
    cin >> guests;
    cin.ignore();
    cout << "\tEnter New Status: ";
    getline(cin, status);

    g->setName(name);
    g->setEmail(email);
    g->setGuests(guests);
    g->setStatus(status);

    cout << "\n\t✔ Guest updated successfully!\n";
}

// ======================= DELETE GUEST FUNCTION =====================
void deleteGuest() {
    int id;
    viewGuests();

    cout << "\n\tEnter ID to delete: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > guestList.size()) {
        throw out_of_range("Invalid ID selected.");
    }

    delete guestList[id - 1];  // free memory
    guestList.erase(guestList.begin() + id - 1);

    cout << "\n\t✔ Guest deleted successfully!\n";
}

// ======================= CLEANUP MEMORY FUNCTION =====================
void cleanup() {
    for (auto g : guestList)
        delete g;
    guestList.clear();
}
