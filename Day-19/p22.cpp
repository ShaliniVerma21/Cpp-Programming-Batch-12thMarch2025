//22. Data validation as Password , email, adhar card, pancard, phone no etc Validator

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <stdexcept>
using namespace std;

// =================== ABSTRACT BASE CLASS ===================
class AbstractValidator {
public:
    virtual bool validate(const string&) const = 0;
    virtual ~AbstractValidator() {}
};

// =================== VALIDATOR CLASSES ===================
class EmailValidator : public AbstractValidator {
public:
    bool validate(const string& email) const override {
        regex pattern(R"(^[\w\.-]+@[\w\.-]+\.\w{2,4}$)");
        return regex_match(email, pattern);
    }
};

class PasswordValidator : public AbstractValidator {
public:
    bool validate(const string& pass) const override {
        // Minimum 6 chars, 1 uppercase, 1 lowercase, 1 digit
        regex pattern(R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d).{6,})");
        return regex_match(pass, pattern);
    }
};

class AadharValidator : public AbstractValidator {
public:
    bool validate(const string& aadhar) const override {
        regex pattern(R"(^\d{12}$)");
        return regex_match(aadhar, pattern);
    }
};

class PANValidator : public AbstractValidator {
public:
    bool validate(const string& pan) const override {
        regex pattern(R"([A-Z]{5}[0-9]{4}[A-Z]{1})");
        return regex_match(pan, pattern);
    }
};

class PhoneValidator : public AbstractValidator {
public:
    bool validate(const string& phone) const override {
        regex pattern(R"(^[6-9]\d{9}$)");
        return regex_match(phone, pattern);
    }
};

// =================== USER CLASS (Encapsulation, OOP) ===================
class User {
private:
    string name, email, password, aadhar, pan, phone;

public:
    // Constructor
    User(string n, string e, string p, string a, string pan_, string ph)
        : name(n), email(e), password(p), aadhar(a), pan(pan_), phone(ph) {}

    void showDetails() const {
        cout << "\n\tName:\t" << name;
        cout << "\n\tEmail:\t" << email;
        cout << "\n\tPhone:\t" << phone;
        cout << "\n\tAadhar:\t" << aadhar;
        cout << "\n\tPAN:\t" << pan << "\n";
    }

    void updateEmail(string newEmail) { email = newEmail; }
    string getName() const { return name; }
};

// =================== GLOBAL VECTOR OF POINTERS ===================
vector<User*> users;

// =================== FUNCTION DECLARATIONS ===================
void menu();
void addUser();
void viewUsers();
void updateUser();
void deleteUser();
bool validateAll(const string&, const string&, const string&, const string&, const string&);

// =================== MAIN FUNCTION ===================
int main() {
    int choice;
    do {
        menu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
                case 1: addUser(); break;
                case 2: viewUsers(); break;
                case 3: updateUser(); break;
                case 4: deleteUser(); break;
                case 5: cout << "\nThank you for using Validator System!\n"; break;
                default: throw runtime_error("Invalid choice.");
            }
        } catch (const exception& e) {
            cout << "\n\t[Error] " << e.what() << "\n";
        }

    } while (choice != 5);

    for (User* u : users) delete u;
    return 0;
}

// =================== MENU ===================
void menu() {
    cout << "\n\n\t====== Data Validator System ======\n";
    cout << "\t1. Add New User\n";
    cout << "\t2. View Users\n";
    cout << "\t3. Update User Email\n";
    cout << "\t4. Delete User\n";
    cout << "\t5. Exit\n";
    cout << "\t===================================\n";
}

// =================== ADD USER ===================
void addUser() {
    string name, email, password, aadhar, pan, phone;

    cout << "\n\tEnter Name: ";
    getline(cin, name);
    cout << "\tEnter Email: ";
    getline(cin, email);
    cout << "\tEnter Password: ";
    getline(cin, password);
    cout << "\tEnter Aadhar No: ";
    getline(cin, aadhar);
    cout << "\tEnter PAN No: ";
    getline(cin, pan);
    cout << "\tEnter Phone No: ";
    getline(cin, phone);

    if (validateAll(email, password, aadhar, pan, phone)) {
        users.push_back(new User(name, email, password, aadhar, pan, phone));
        cout << "\n\t✔ User added successfully.\n";
    } else {
        throw invalid_argument("Validation failed. Please check inputs.");
    }
}

// =================== VALIDATE ALL FIELDS ===================
bool validateAll(const string& email, const string& pass, const string& aadhar, const string& pan, const string& phone) {
    EmailValidator e;
    PasswordValidator p;
    AadharValidator a;
    PANValidator panVal;
    PhoneValidator ph;

    return e.validate(email) && p.validate(pass) && a.validate(aadhar) && panVal.validate(pan) && ph.validate(phone);
}

// =================== VIEW USERS ===================
void viewUsers() {
    if (users.empty()) {
        cout << "\n\tNo users found.\n";
        return;
    }

    cout << "\n\t--- Registered Users ---\n";
    for (size_t i = 0; i < users.size(); ++i) {
        cout << "\nUser ID: " << i + 1;
        users[i]->showDetails();
    }
}

// =================== UPDATE USER EMAIL ===================
void updateUser() {
    int id;
    string newEmail;

    viewUsers();
    cout << "\n\tEnter User ID to update email: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > users.size()) {
        throw out_of_range("Invalid ID.");
    }

    cout << "\tEnter new email: ";
    getline(cin, newEmail);
    EmailValidator ev;
    if (!ev.validate(newEmail)) {
        throw invalid_argument("Invalid email format.");
    }

    users[id - 1]->updateEmail(newEmail);
    cout << "\n\t✔ Email updated.\n";
}

// =================== DELETE USER ===================
void deleteUser() {
    int id;
    viewUsers();
    cout << "\n\tEnter User ID to delete: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > users.size()) {
        throw out_of_range("Invalid ID.");
    }

    delete users[id - 1];
    users.erase(users.begin() + id - 1);
    cout << "\n\t✔ User deleted.\n";
}
