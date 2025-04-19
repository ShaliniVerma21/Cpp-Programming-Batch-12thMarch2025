//4. Contact Management System

#include <iostream>
#include <vector>

class Contact {
public:
    std::string name;
    std::string phoneNumber;

    Contact(std::string n, std::string p) : name(n), phoneNumber(p) {}
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void searchContact(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Contact found: " << contact.name << ", Phone: " << contact.phoneNumber << "\n";
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }
};