//2. Inventory Management System

#include <iostream>
#include <vector>

class Item {
public:
    std::string name;
    int quantity;
    double price;

    Item(std::string n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    void displayItems() const {
        for (const auto& item : items) {
            std::cout << "Item: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << "\n";
        }
    }
};