//Problem 7: Inventory Tracker

#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

void displayInventory(Product products[], int count) {
    cout << "Product Name\tQuantity\tPrice\n";
    for (int i = 0; i < count; i++) {
        cout << products[i].name << "\t\t" << products[i].quantity << "\t\t" << products[i].price << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    Product products[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter product name, quantity, and price: ";
        cin >> products[i].name >> products[i].quantity >> products[i].price;
    }
    displayInventory(products, n);
    return 0;
}