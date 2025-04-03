//5. Basic Inventory System
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numProducts = 3;
    string products[numProducts];
    float prices[numProducts];

    // Input product names and prices
    for (int i = 0; i < numProducts; i++) {
        cout << "Enter product name " << (i + 1) << ": ";
        cin >> products[i];
        cout << "Enter price for " << products[i] << ": ";
        cin >> prices[i];
    }

    // Display inventory
    cout << "\nInventory:\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "Product: " << products[i] << ", Price: $" << prices[i] << endl;
    }

    return 0;
}