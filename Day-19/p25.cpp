//25. Wedding planner

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// ================= ABSTRACT BASE CLASS ===================
class AbstractService {
public:
    virtual void showService() const = 0; // pure virtual function
    virtual ~AbstractService() {}
};

// =============== SERVICE CLASS (Encapsulation + Abstraction) ==============
class Service : public AbstractService {
protected:
    string serviceName;
    float cost;
    string vendor;

public:
    // Constructor
    Service(string s, float c, string v) : serviceName(s), cost(c), vendor(v) {}

    // Setters
    void setServiceName(string s) { serviceName = s; }
    void setCost(float c) { cost = c; }
    void setVendor(string v) { vendor = v; }

    // Getters
    string getServiceName() const { return serviceName; }

    // Display (Polymorphic)
    virtual void showService() const override {
        cout << "\n\tService:\t" << serviceName
             << "\n\tVendor:\t\t" << vendor
             << "\n\tCost:\t\t$" << cost << "\n";
    }

    virtual ~Service() {}
};

// ============ PREMIUM SERVICE CLASS (Inheritance + Polymorphism) ============
class PremiumService : public Service {
    string specialNote;

public:
    PremiumService(string s, float c, string v, string note)
        : Service(s, c, v), specialNote(note) {}

    void showService() const override {
        Service::showService();
        cout << "\tNote:\t\t" << specialNote << "\n";
    }
};

// =============== GLOBAL VECTOR WITH POINTERS ===================
vector<AbstractService*> serviceList;

// =============== FUNCTION DECLARATIONS ===================
void showMenu();
void addService();
void viewServices();
void updateService();
void deleteService();
void cleanup();

// ================= MAIN FUNCTION =================
int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
                case 1: addService(); break;
                case 2: viewServices(); break;
                case 3: updateService(); break;
                case 4: deleteService(); break;
                case 5: cout << "\nThank you for using Wedding Planner System!\n"; break;
                default: throw runtime_error("Invalid choice entered. Try again.");
            }
        } catch (const exception& e) {
            cout << "\n\tError: " << e.what() << "\n";
        }

    } while (choice != 5);

    cleanup();
    return 0;
}

// ================= DISPLAY MENU FUNCTION =================
void showMenu() {
    cout << "\n\n\t========== Wedding Planner System ==========\n";
    cout << "\t1. Add Service\n";
    cout << "\t2. View All Services\n";
    cout << "\t3. Update Service\n";
    cout << "\t4. Delete Service\n";
    cout << "\t5. Exit\n";
    cout << "\t============================================\n";
}

// ================= ADD SERVICE FUNCTION =================
void addService() {
    string name, vendor, note, isPremium;
    float cost;

    cout << "\n\tEnter Service Name (e.g. Catering, Photography): ";
    getline(cin, name);
    cout << "\tEnter Vendor Name: ";
    getline(cin, vendor);
    cout << "\tEnter Cost ($): ";
    cin >> cost;
    cin.ignore();
    cout << "\tIs this a Premium Service? (yes/no): ";
    getline(cin, isPremium);

    if (isPremium == "yes") {
        cout << "\tEnter Special Note: ";
        getline(cin, note);
        serviceList.push_back(new PremiumService(name, cost, vendor, note));
    } else {
        serviceList.push_back(new Service(name, cost, vendor));
    }

    cout << "\n\t✔ Service added successfully!\n";
}

// ================= VIEW SERVICES FUNCTION =================
void viewServices() {
    if (serviceList.empty()) {
        cout << "\n\tNo services found!\n";
        return;
    }

    cout << "\n\t--- Wedding Services List ---\n";
    for (size_t i = 0; i < serviceList.size(); ++i) {
        cout << "\n\tID: " << i + 1;
        serviceList[i]->showService();
    }
}

// ================= UPDATE SERVICE FUNCTION =================
void updateService() {
    int id;
    viewServices();

    cout << "\n\tEnter Service ID to update: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > serviceList.size()) {
        throw out_of_range("Invalid ID selected.");
    }

    Service* s = dynamic_cast<Service*>(serviceList[id - 1]);
    if (!s) throw runtime_error("Cannot update this service type.");

    string name, vendor;
    float cost;

    cout << "\tEnter New Service Name: ";
    getline(cin, name);
    cout << "\tEnter New Vendor Name: ";
    getline(cin, vendor);
    cout << "\tEnter New Cost ($): ";
    cin >> cost;
    cin.ignore();

    s->setServiceName(name);
    s->setVendor(vendor);
    s->setCost(cost);

    cout << "\n\t✔ Service updated successfully!\n";
}

// ================= DELETE SERVICE FUNCTION =================
void deleteService() {
    int id;
    viewServices();

    cout << "\n\tEnter Service ID to delete: ";
    cin >> id;
    cin.ignore();

    if (id < 1 || id > serviceList.size()) {
        throw out_of_range("Invalid ID selected.");
    }

    delete serviceList[id - 1];
    serviceList.erase(serviceList.begin() + id - 1);

    cout << "\n\t✔ Service deleted successfully!\n";
}

// ================= CLEANUP FUNCTION (Free memory) =================
void cleanup() {
    for (auto s : serviceList)
        delete s;
    serviceList.clear();
}
