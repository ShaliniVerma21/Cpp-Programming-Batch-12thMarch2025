//E-commerce Product Catalog & Discounted Price on products

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For setting precision
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for product categories
enum class ProductCategory {
    ELECTRONICS,
    CLOTHING,
    GROCERY,
    HOME_APPLIANCES
};

// Structure for a product
struct Product {
    string name; // Name of the product
    double price; // Original price of the product
    ProductCategory category; // Category of the product

    // Constructor for Product
    Product(string n, double p, ProductCategory c) 
        : name(n), price(p), category(c) {}

    // Function to apply a discount to the product
    double applyDiscount(double discountPercentage) {
        if (discountPercentage < 0 || discountPercentage > 100) {
            throw invalid_argument("Discount percentage must be between 0 and 100.");
        }
        return price - (price * discountPercentage / 100);
    }
};

// Base class for ProductCatalog
class ProductCatalog {
protected:
    vector<Product> products; // List of products in the catalog

public:
    // Function to add a product to the catalog
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Function to display all products
    void displayProducts() const {
        cout << "Product Catalog:\n";
        for (const auto& product : products) {
            cout << "Name: " << product.name 
                 << ", Price: $" << fixed << setprecision(2) << product.price 
                 << ", Category: " << getCategoryString(product.category) << endl;
        }
    }

    // Function to get string representation of product category
    string getCategoryString(ProductCategory category) const {
        switch (category) {
            case ProductCategory::ELECTRONICS: return "Electronics";
            case ProductCategory::CLOTHING: return "Clothing";
            case ProductCategory::GROCERY: return "Grocery";
            case ProductCategory::HOME_APPLIANCES: return "Home Appliances";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~ProductCatalog() {}
};

// Derived class for DiscountedProductCatalog
class DiscountedProductCatalog : public ProductCatalog {
public:
    // Function to display products with discounted prices
    void displayDiscountedProducts(double discountPercentage) const {
        cout << "Discounted Product Catalog (Discount: " << discountPercentage << "%):\n";
        for (const auto& product : products) {
            double discountedPrice = product.applyDiscount(discountPercentage);
            cout << "Name: " << product.name 
                 << ", Original Price: $" << fixed << setprecision(2) << product.price 
                 << ", Discounted Price: $" << discountedPrice 
                 << ", Category: " << getCategoryString(product.category) << endl;
        }
    }
};

int main() {
    // Create an instance of DiscountedProductCatalog
    DiscountedProductCatalog catalog;

    // Add products to the catalog
    catalog.addProduct(Product("Smartphone", 699.99, ProductCategory::ELECTRONICS));
    catalog.addProduct(Product("T-Shirt", 19.99, ProductCategory::CLOTHING));
    catalog.addProduct(Product("Coffee Maker", 49.99, ProductCategory::HOME_APPLIANCES));
    catalog.addProduct(Product("Organic Apples", 3.99, ProductCategory::GROCERY));

    // Display all products
    catalog.displayProducts();
    cout << endl;

    // Display discounted products with a 10% discount
    double discountPercentage = 10.0;
    catalog.displayDiscountedProducts(discountPercentage);

    return 0;
}