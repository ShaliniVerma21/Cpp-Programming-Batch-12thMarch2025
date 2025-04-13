//Problem 1: Simple Billing System

#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    float price;
    int quantity;
};

void printBill(Item items[], int count) {
    float total = 0;
    cout << fixed << setprecision(2);
    cout << "Item Name\tPrice\tQuantity\tTotal\n";
    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].price * items[i].quantity;
        cout << items[i].name << "\t\t" << items[i].price << "\t" << items[i].quantity << "\t\t" << itemTotal << endl;
        total += itemTotal;
    }
    cout << "Total Bill: " << total << endl;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    Item items[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter item name, price, and quantity: ";
        cin >> items[i].name >> items[i].price >> items[i].quantity;
    }
    printBill(items, n);
    return 0;
}