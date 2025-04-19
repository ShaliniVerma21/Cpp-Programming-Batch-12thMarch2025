//8. Smartphone Class

#include <iostream>
using namespace std;

class Smartphone {
private:
    string brand;
    string model;
    double price;

public:
    Smartphone(string b, string m, double p) {
        brand = b;
        model = m;
        price = p;
    }

    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: $" << price << endl;
    }
};

int main() {
    Smartphone phone("Apple", "iPhone 13", 999.99);
    phone.displayInfo();
    return 0;
}