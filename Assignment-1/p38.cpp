//12. allows users to browse products, add them to a cart, and checkout.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for std::setprecision
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}
};

class ShoppingCart {
private:
    vector<Product> cart;

public:
    void addProduct(const Product& product) {
        cart.push_back(product);
        cout << product.name << " has been added to your cart." << endl;
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }
        cout << "Your Shopping Cart:" << endl;
        for (const auto& product : cart) {
            cout << "- " << product.name << ": $" << fixed << setprecision(2) << product.price << endl;
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& product : cart) {
            total += product.price;
        }
        return total;
    }

    void clearCart() {
        cart.clear();
        cout << "Your cart has been cleared." << endl;
    }
};

class OnlineShoppingSystem {
private:
    vector<Product> products;
    ShoppingCart cart;

public:
    OnlineShoppingSystem() {
        // Sample products
        products.push_back(Product("Laptop", 999.99));
        products.push_back(Product("Smartphone", 499.99));
        products.push_back(Product("Headphones", 199.99));
        products.push_back(Product("Smartwatch", 299.99));
        products.push_back(Product("Tablet", 399.99));
    }

    void displayProducts() {
        cout << "Available Products:" << endl;
        for (size_t i = 0; i < products.size(); i++) {
            cout << i + 1 << ". " << products[i].name << " - $" << fixed << setprecision(2) << products[i].price << endl;
        }
    }

    void startShopping() {
        int choice;
        do {
            cout << "\nWelcome to the Online Shopping System!" << endl;
            displayProducts();
            cout << "Enter the product number to add to cart (0 to checkout): ";
            cin >> choice;

            if (choice > 0 && choice <= products.size()) {
                cart.addProduct(products[choice - 1]);
            } else if (choice == 0) {
                double total = cart.calculateTotal();
                cout << "Your total is: $" << fixed << setprecision(2) << total << endl;
                cout << "Thank you for shopping with us!" << endl;
                cart.clearCart();
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }

            char viewCartChoice;
            cout << "Would you like to view your cart? (y/n): ";
            cin >> viewCartChoice;
            if (viewCartChoice == 'y' || viewCartChoice == 'Y') {
                cart.viewCart();
            }

        } while (choice != 0);
    }
};

int main() {
    OnlineShoppingSystem shoppingSystem;
    shoppingSystem.startShopping();
    return 0;
}