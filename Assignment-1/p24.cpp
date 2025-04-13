//Problem 23: Shopping Cart Management

#include <iostream>
#include <string>
using namespace std;

struct CartItem {
    string productName;
    float price;
    int quantity;
};

void displayCart(CartItem cart[], int count) {
    float total = 0;
    cout << "Product Name\tPrice\tQuantity\tTotal\n";
    for (int i = 0; i < count; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        cout << cart[i].productName << "\t\t" << cart[i].price << "\t" << cart[i].quantity << "\t\t" << itemTotal << endl;
        total += itemTotal;
    }
    cout << "Total Cart Value: " << total << endl;
}

int main() {
    int n;
    cout << "Enter number of items in cart: ";
    cin >> n;
    CartItem cart[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter product name, price, and quantity: ";
        cin >> cart[i].productName >> cart[i].price >> cart[i].quantity;
    }
    displayCart(cart, n);
    return 0;
}