//23.  Bill Split Calculator

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// =================== ABSTRACT BASE CLASS ===================
class AbstractMember {
public:
    virtual void showDetails() const = 0;
    virtual ~AbstractMember() {}
};

// =================== BILL MEMBER CLASS (Encapsulation + Abstraction) ===================
class BillMember : public AbstractMember {
protected:
    string name;
    float amount;

public:
    // Constructor
    BillMember(string n, float a) : name(n), amount(a) {}

    // Setters
    void setName(string n) { name = n; }
    void setAmount(float a) { amount = a; }

    // Getters
    string getName() const { return name; }
    float getAmount() const { return amount; }

    // Display (Polymorphism)
    virtual void showDetails() const override {
        cout << "\tName:\t" << name << "\n"
             << "\tPaid:\t$" << fixed << setprecision(2) << amount << "\n";
    }

    virtual ~BillMember() {}
};

// =================== PREMIUM MEMBER (Inheritance + Polymorphism) ===================
class PremiumBillMember : public BillMember {
    string note;

public:
    PremiumBillMember(string n, float a, string note) : BillMember(n, a), note(note) {}

    void showDetails() const override {
        BillMember::showDetails();
        cout << "\tNote:\t" << note << "\n";
    }
};

// =================== GLOBAL VECTOR OF POINTERS ===================
vector<BillMember*> memberList;

// =================== FUNCTION DECLARATIONS ===================
void showMenu();
void addMember();
void viewMembers();
void updateMember();
void deleteMember();
void calculateSplit();
void cleanup();

// =================== MAIN FUNCTION ===================
int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
                case 1: addMember(); break;
                case 2: viewMembers(); break;
                case 3: updateMember(); break;
                case 4: deleteMember(); break;
                case 5: calculateSplit(); break;
                case 6: cout << "\nThank you for using the Bill Split Calculator!\n"; break;
                default: throw runtime_error("Invalid choice. Please try again.");
            }
        } catch (const exception& e) {
            cout << "\n\tError: " << e.what() << "\n";
        }

    } while (choice != 6);

    cleanup();
    return 0;
}

// =================== SHOW MENU ===================
void showMenu() {
    cout << "\n\n\t====== Bill Split Calculator ======\n";
    cout << "\t1. Add Member\n";
    cout << "\t2. View All Members\n";
    cout << "\t3. Update Member Amount\n";
    cout << "\t4. Delete Member\n";
    cout << "\t5. Calculate Split\n";
    cout << "\t6. Exit\n";
    cout << "\t==================================\n";
}

// =================== ADD MEMBER ===================
void addMember() {
    string name, isPremium, note;
    float amount;

    cout << "\n\tEnter Member Name: ";
    getline(cin, name);
    cout << "\tEnter Amount Paid ($): ";
    cin >> amount;
    cin.ignore();
    cout << "\tIs Premium Member? (yes/no): ";
    getline(cin, isPremium);

    if (isPremium == "yes") {
        cout << "\tEnter Note: ";
        getline(cin, note);
        memberList.push_back(new PremiumBillMember(name, amount, note));
    } else {
        memberList.push_back(new BillMember(name, amount));
    }

    cout << "\n\t✔ Member added successfully!\n";
}

// =================== VIEW MEMBERS ===================
void viewMembers() {
    if (memberList.empty()) {
        cout << "\n\tNo members added yet.\n";
        return;
    }

    cout << "\n\t--- Member Contributions ---\n";
    for (size_t i = 0; i < memberList.size(); ++i) {
        cout << "\n\tID: " << i + 1 << "\n";
        memberList[i]->showDetails();
    }
}

// =================== UPDATE MEMBER ===================
void updateMember() {
    int id;
    float newAmount;
    viewMembers();

    cout << "\n\tEnter Member ID to update: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > memberList.size()) {
        throw out_of_range("Invalid ID entered.");
    }

    cout << "\tEnter New Amount: ";
    cin >> newAmount;
    cin.ignore();

    memberList[id - 1]->setAmount(newAmount);
    cout << "\n\t✔ Member amount updated.\n";
}

// =================== DELETE MEMBER ===================
void deleteMember() {
    int id;
    viewMembers();

    cout << "\n\tEnter Member ID to delete: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > memberList.size()) {
        throw out_of_range("Invalid ID entered.");
    }

    delete memberList[id - 1];
    memberList.erase(memberList.begin() + id - 1);
    cout << "\n\t✔ Member deleted successfully.\n";
}

// =================== CALCULATE SPLIT ===================
void calculateSplit() {
    if (memberList.empty()) {
        cout << "\n\tNo data to calculate.\n";
        return;
    }

    float total = 0;
    for (auto m : memberList) {
        total += m->getAmount();
    }

    float split = total / memberList.size();

    cout << "\n\t=== Bill Summary ===\n";
    cout << "\tTotal Bill:\t$" << fixed << setprecision(2) << total << "\n";
    cout << "\tSplit Per Person:\t$" << fixed << setprecision(2) << split << "\n";

    cout << "\n\t--- Balances ---\n";
    for (auto m : memberList) {
        float balance = m->getAmount() - split;
        cout << "\t" << m->getName() << " ";
        if (balance > 0)
            cout << "should receive $" << balance << "\n";
        else if (balance < 0)
            cout << "should pay $" << -balance << "\n";
        else
            cout << "is settled up.\n";
    }
}

// =================== CLEANUP MEMORY ===================
void cleanup() {
    for (auto m : memberList)
        delete m;
    memberList.clear();
}
