//5. Address Book Manager

#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract base class (Abstraction)
class ContactBase {
public:
    virtual void display() const = 0;
    virtual ~ContactBase() {}
};

// Contact class implementing ContactBase (Encapsulation + Inheritance)
class Contact : public ContactBase {
private:
    int id;
    string name;
    string phone;
    string email;
    string address;

public:
    // Constructor
    Contact(int i, string n, string p, string e, string a)
        : id(i), name(n), phone(p), email(e), address(a) {}

    // Accessor
    int getId() const { return id; }

    // Mutator for update
    void update(string p, string e, string a) {
        phone = p;
        email = e;
        address = a;
    }

    // Display override (Polymorphism)
    void display() const override {
        cout << left << setw(5) << id
             << setw(15) << name
             << setw(15) << phone
             << setw(25) << email
             << address << endl;
    }
};

// Manager class for CRUD operations
class AddressBook {
private:
    map<int, Contact*> contacts;
    int idCounter;

public:
    AddressBook() : idCounter(1) {}

    // Add new contact
    void addContact(string name, string phone, string email, string address) {
        Contact* c = new Contact(idCounter, name, phone, email, address);
        contacts[idCounter] = c;
        cout << "✅ Contact added with ID: " << idCounter << "\n";
        idCounter++;
    }

    // Display all contacts
    void displayContacts() {
        if (contacts.empty()) {
            cout << "📭 No contacts to display.\n";
            return;
        }
        cout << "\n📒 ADDRESS BOOK\n";
        cout << left << setw(5) << "ID"
             << setw(15) << "Name"
             << setw(15) << "Phone"
             << setw(25) << "Email"
             << "Address\n";
        cout << "------------------------------------------------------------------\n";
        for (auto& [id, contact] : contacts) {
            contact->display();
        }
    }

    // Update a contact
    void updateContact(int id, string phone, string email, string address) {
        if (contacts.find(id) == contacts.end())
            throw runtime_error("❌ Contact not found.");
        contacts[id]->update(phone, email, address);
        cout << "🔁 Contact updated.\n";
    }

    // Delete a contact
    void deleteContact(int id) {
        if (contacts.find(id) == contacts.end())
            throw runtime_error("❌ Contact not found.");
        delete contacts[id];
        contacts.erase(id);
        cout << "🗑️ Contact deleted.\n";
    }

    // Destructor
    ~AddressBook() {
        for (auto& [id, contact] : contacts)
            delete contact;
    }
};

// Function to display main menu
void showMenu() {
    cout << "\n📌 ADDRESS BOOK MENU\n";
    cout << "--------------------------\n";
    cout << "1. Add Contact\n";
    cout << "2. View All Contacts\n";
    cout << "3. Update Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    AddressBook book;
    int choice, id;
    string name, phone, email, address;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear buffer

        try {
            switch (choice) {
                case 1:
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Enter phone: ";
                    getline(cin, phone);
                    cout << "Enter email: ";
                    getline(cin, email);
                    cout << "Enter address: ";
                    getline(cin, address);
                    book.addContact(name, phone, email, address);
                    break;

                case 2:
                    book.displayContacts();
                    break;

                case 3:
                    cout << "Enter ID to update: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter new phone: ";
                    getline(cin, phone);
                    cout << "Enter new email: ";
                    getline(cin, email);
                    cout << "Enter new address: ";
                    getline(cin, address);
                    book.updateContact(id, phone, email, address);
                    break;

                case 4:
                    cout << "Enter ID to delete: ";
                    cin >> id;
                    book.deleteContact(id);
                    break;

                case 5:
                    cout << "👋 Exiting Address Book. Have a great day!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Try again.\n";
            }
        } catch (exception &e) {
            cout << "❗ Exception: " << e.what() << endl;
        }

    } while (choice != 5);

    return 0;
}
