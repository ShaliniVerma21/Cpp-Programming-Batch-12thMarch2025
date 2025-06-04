//12. Inventory Tracker

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract class for abstraction
class InventoryInterface {
public:
    virtual void addItem() = 0;
    virtual void viewItems() = 0;
    virtual void updateItem() = 0;
    virtual void deleteItem() = 0;
    virtual ~InventoryInterface() {}
};

// Encapsulated Item class
class Item {
private:
    int itemId;
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Item(int id, string n, int qty, double p)
        : itemId(id), name(n), quantity(qty), price(p) {}

    // Getters
    int getId() const { return itemId; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Update item quantity and price
    void update(int qty, double p) {
        if (qty < 0 || p < 0)
            throw invalid_argument("Quantity and price must be positive.");
        quantity = qty;
        price = p;
    }

    // Display item info
    void display() const {
        cout << left << setw(10) << itemId
             << setw(20) << name
             << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << price << "\n";
    }
};

// Derived class: Inventory System
class InventorySystem : public InventoryInterface {
private:
    map<int, Item> inventory; // Using STL map for fast lookup

public:
    // Add item to inventory
    void addItem() override {
        int id, qty;
        string name;
        double price;

        cout << "\nEnter Item ID: ";
        cin >> id;

        if (inventory.find(id) != inventory.end()) {
            cout << "❌ Item already exists!\n";
            return;
        }

        cin.ignore(); // clear input buffer
        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price: ";
        cin >> price;

        try {
            Item newItem(id, name, qty, price);
            inventory[id] = newItem;
            cout << "✅ Item added successfully!\n";
        } catch (exception &e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // View all items
    void viewItems() override {
        if (inventory.empty()) {
            cout << "\n📦 Inventory is empty.\n";
            return;
        }

        cout << "\n📋 Current Inventory:\n";
        cout << left << setw(10) << "Item ID"
             << setw(20) << "Item Name"
             << setw(10) << "Qty"
             << setw(10) << "Price\n";
        cout << string(50, '-') << "\n";

        for (const auto &pair : inventory) {
            pair.second.display();
        }
    }

    // Update item
    void updateItem() override {
        int id, qty;
        double price;

        cout << "\nEnter Item ID to Update: ";
        cin >> id;

        auto it = inventory.find(id);
        if (it == inventory.end()) {
            cout << "❌ Item not found!\n";
            return;
        }

        cout << "Enter New Quantity: ";
        cin >> qty;
        cout << "Enter New Price: ";
        cin >> price;

        try {
            it->second.update(qty, price);
            cout << "✅ Item updated successfully!\n";
        } catch (exception &e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // Delete item
    void deleteItem() override {
        int id;
        cout << "\nEnter Item ID to Delete: ";
        cin >> id;

        if (inventory.erase(id)) {
            cout << "✅ Item deleted successfully!\n";
        } else {
            cout << "❌ Item not found!\n";
        }
    }
};

// Menu function
void showMenu() {
    cout << "\n========= 🛒 Inventory Tracker Menu =========\n";
    cout << "1. Add New Item\n";
    cout << "2. View All Items\n";
    cout << "3. Update Item\n";
    cout << "4. Delete Item\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    InventorySystem system;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1: system.addItem(); break;
                case 2: system.viewItems(); break;
                case 3: system.updateItem(); break;
                case 4: system.deleteItem(); break;
                case 5: cout << "\n👋 Exiting Inventory Tracker. Goodbye!\n"; break;
                default: throw invalid_argument("❌ Invalid choice! Enter 1-5.");
            }

        } catch (exception &e) {
            cout << "\n⚠️ Exception: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
