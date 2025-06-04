//11.Order Tracking System &  Product Pricing List

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract class for Order System
class OrderInterface {
public:
    virtual void addProduct() = 0;
    virtual void showProductList() = 0;
    virtual void createOrder() = 0;
    virtual void viewOrders() = 0;
    virtual ~OrderInterface() {}
};

// Product class using encapsulation
class Product {
private:
    int productId;
    string name;
    double price;

public:
    Product() {}
    Product(int id, string n, double p) : productId(id), name(n), price(p) {}

    int getId() const { return productId; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const {
        cout << left << setw(10) << productId << setw(25) << name << "₹ " << fixed << setprecision(2) << price << "\n";
    }
};

// Order class for storing orders
class Order {
private:
    int orderId;
    vector<Product> products;
    double total;

public:
    Order(int id, vector<Product> pList) : orderId(id), products(pList) {
        total = 0.0;
        for (const auto& p : products) {
            total += p.getPrice();
        }
    }

    void display() const {
        cout << "\n🧾 Order ID: " << orderId << "\n";
        cout << "----------------------------------\n";
        for (const auto& p : products) {
            p.display();
        }
        cout << "----------------------------------\n";
        cout << "Total: ₹ " << fixed << setprecision(2) << total << "\n";
    }
};

// Main system class
class OrderSystem : public OrderInterface {
private:
    map<int, Product> productList;
    map<int, Order> orders;
    int nextOrderId = 1;

public:
    // Add a new product to the list
    void addProduct() override {
        int id;
        string name;
        double price;

        cout << "\nEnter Product ID: ";
        cin >> id;

        if (productList.find(id) != productList.end()) {
            cout << "❌ Product already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Product Price: ₹";
        cin >> price;

        try {
            if (price < 0) throw invalid_argument("Price cannot be negative.");
            productList[id] = Product(id, name, price);
            cout << "✅ Product added successfully!\n";
        } catch (exception &e) {
            cout << "⚠️ Error: " << e.what() << "\n";
        }
    }

    // Display product price list
    void showProductList() override {
        if (productList.empty()) {
            cout << "\n📦 No products in the list.\n";
            return;
        }

        cout << "\n📋 Product Price List:\n";
        cout << left << setw(10) << "Prod ID" << setw(25) << "Name" << "Price\n";
        cout << string(45, '-') << "\n";

        for (const auto& pair : productList) {
            pair.second.display();
        }
    }

    // Create a new order
    void createOrder() override {
        vector<Product> selectedProducts;
        int pid;
        char choice;

        if (productList.empty()) {
            cout << "\n🚫 No products available to order!\n";
            return;
        }

        do {
            cout << "\nEnter Product ID to add to order: ";
            cin >> pid;

            auto it = productList.find(pid);
            if (it != productList.end()) {
                selectedProducts.push_back(it->second);
                cout << "✅ Product added to order.\n";
            } else {
                cout << "❌ Invalid Product ID!\n";
            }

            cout << "Do you want to add another product? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        if (!selectedProducts.empty()) {
            Order newOrder(nextOrderId++, selectedProducts);
            orders[newOrderId() - 1] = newOrder;
            cout << "✅ Order created successfully!\n";
        } else {
            cout << "⚠️ No products selected. Order not created.\n";
        }
    }

    // Display all orders
    void viewOrders() override {
        if (orders.empty()) {
            cout << "\n🗂️ No orders placed yet.\n";
            return;
        }

        for (const auto& pair : orders) {
            pair.second.display();
        }
    }

    // Helper to get current order ID
    int newOrderId() {
        return nextOrderId;
    }
};

// Display menu
void showMenu() {
    cout << "\n=========== 🛒 Order Tracking Menu ===========\n";
    cout << "1. Add New Product\n";
    cout << "2. Show Product Price List\n";
    cout << "3. Create Order\n";
    cout << "4. View All Orders\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    OrderSystem system;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1: system.addProduct(); break;
                case 2: system.showProductList(); break;
                case 3: system.createOrder(); break;
                case 4: system.viewOrders(); break;
                case 5: cout << "\n👋 Thank you for using Order Tracker!\n"; break;
                default: throw invalid_argument("❌ Invalid option. Enter 1-5.");
            }

        } catch (exception &e) {
            cout << "⚠️ Exception: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
