//19.Online Food Order Menu

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract base class defining interface for Food Menu system
class FoodMenuInterface {
public:
    virtual void addItem() = 0;
    virtual void viewMenu() = 0;
    virtual void updateItem() = 0;
    virtual void deleteItem() = 0;
    virtual void placeOrder() = 0;
    virtual ~FoodMenuInterface() {}
};

// Class to encapsulate food item details
class FoodItem {
private:
    int itemID;
    string name;
    string category;  // e.g., Starter, Main Course, Dessert
    double price;

public:
    FoodItem() {}
    FoodItem(int id, string n, string c, double p) : itemID(id), name(n), category(c), price(p) {}

    int getItemID() const { return itemID; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }

    void setName(string n) { name = n; }
    void setCategory(string c) { category = c; }
    void setPrice(double p) { price = p; }

    void display() const {
        cout << "\n🍽️ Item ID: " << itemID
             << "\n🍔 Name: " << name
             << "\n📂 Category: " << category
             << "\n💰 Price: ₹" << price << "\n";
    }
};

// Main class managing food menu & orders with CRUD & order placement
class FoodOrderSystem : public FoodMenuInterface {
private:
    map<int, FoodItem> menuItems;     // itemID -> FoodItem
    map<int, int> currentOrder;       // itemID -> quantity

public:
    FoodOrderSystem() {
        cout << "\n🍴 Welcome to Online Food Order System 🍴\n";
    }

    // Add a new item to menu
    void addItem() override {
        int id;
        string name, category;
        double price;

        cout << "\nEnter Item ID: ";
        cin >> id;
        cin.ignore();

        if (menuItems.find(id) != menuItems.end()) {
            cout << "❌ Item ID already exists!\n";
            return;
        }

        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Category (Starter/Main Course/Dessert): ";
        getline(cin, category);
        cout << "Enter Price (₹): ";
        cin >> price;
        cin.ignore();

        if(price < 0) {
            cout << "❌ Price cannot be negative.\n";
            return;
        }

        FoodItem item(id, name, category, price);
        menuItems[id] = item;

        cout << "✅ Item added successfully.\n";
    }

    // View all menu items
    void viewMenu() override {
        if (menuItems.empty()) {
            cout << "\n⚠️ Menu is empty.\n";
            return;
        }

        cout << "\n========== 📋 Food Menu ==========\n";
        for (auto& it : menuItems) {
            it.second.display();
        }
    }

    // Update existing menu item
    void updateItem() override {
        int id;
        cout << "\nEnter Item ID to update: ";
        cin >> id;
        cin.ignore();

        auto it = menuItems.find(id);
        if (it == menuItems.end()) {
            cout << "❌ Item not found.\n";
            return;
        }

        string name, category;
        double price;
        cout << "Enter new Item Name: ";
        getline(cin, name);
        cout << "Enter new Category: ";
        getline(cin, category);
        cout << "Enter new Price (₹): ";
        cin >> price;
        cin.ignore();

        if(price < 0) {
            cout << "❌ Price cannot be negative.\n";
            return;
        }

        it->second.setName(name);
        it->second.setCategory(category);
        it->second.setPrice(price);

        cout << "✅ Item updated successfully.\n";
    }

    // Delete a menu item
    void deleteItem() override {
        int id;
        cout << "\nEnter Item ID to delete: ";
        cin >> id;
        cin.ignore();

        if (menuItems.erase(id)) {
            cout << "✅ Item deleted successfully.\n";
        } else {
            cout << "❌ Item ID not found.\n";
        }
    }

    // Place order by selecting items & quantities
    void placeOrder() override {
        if (menuItems.empty()) {
            cout << "\n⚠️ Menu is empty. Cannot place order.\n";
            return;
        }

        cout << "\n🛒 Place Your Order:\n";
        char choice;
        do {
            int id, qty;
            cout << "Enter Item ID to order: ";
            cin >> id;
            cin.ignore();

            auto it = menuItems.find(id);
            if (it == menuItems.end()) {
                cout << "❌ Invalid Item ID.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> qty;
            cin.ignore();

            if(qty <= 0) {
                cout << "❌ Quantity should be positive.\n";
                continue;
            }

            currentOrder[id] += qty;
            cout << "✅ Added " << qty << " x " << it->second.getName() << " to your order.\n";

            cout << "Add more items? (Y/N): ";
            cin >> choice;
            cin.ignore();

        } while (choice == 'Y' || choice == 'y');

        showOrderSummary();
    }

private:
    // Display order summary and total amount
    void showOrderSummary() {
        if (currentOrder.empty()) {
            cout << "\n🛒 Your order is empty.\n";
            return;
        }

        cout << "\n====== 🧾 Order Summary ======\n";
        double total = 0.0;
        for (auto& orderItem : currentOrder) {
            int id = orderItem.first;
            int qty = orderItem.second;
            FoodItem& item = menuItems[id];
            double amount = qty * item.getPrice();

            cout << qty << " x " << item.getName() << " @ ₹" << item.getPrice()
                 << " = ₹" << amount << "\n";

            total += amount;
        }
        cout << "--------------------------\n";
        cout << "Total Amount: ₹" << total << "\n";
        cout << "Thank you for your order! 🍽️\n";
        currentOrder.clear(); // Clear order after checkout
    }
};

// Display menu options
void showMenu() {
    cout << "\n\n========== Online Food Order Menu ==========\n";
    cout << "1. Add Food Item\n";
    cout << "2. View Food Menu\n";
    cout << "3. Update Food Item\n";
    cout << "4. Delete Food Item\n";
    cout << "5. Place Order\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    FoodOrderSystem system;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: system.addItem(); break;
                case 2: system.viewMenu(); break;
                case 3: system.updateItem(); break;
                case 4: system.deleteItem(); break;
                case 5: system.placeOrder(); break;
                case 6: cout << "\n👋 Thanks for using Online Food Order System. Goodbye!\n"; break;
                default: throw invalid_argument("❌ Invalid choice. Please enter 1-6.");
            }
        } catch (const exception& e) {
            cout << "\n[Error] " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}
