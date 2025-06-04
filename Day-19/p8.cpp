//8. Coupon Code System

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract Base Class for Coupon
class Coupon {
public:
    virtual void display() const = 0; // Abstract Method
    virtual ~Coupon() {}             // Virtual Destructor
};

// Derived class: CouponDetails
class CouponDetails : public Coupon {
private:
    string code;
    string description;
    float discount;
    string expiry;

public:
    // Constructor
    CouponDetails(string c, string d, float dis, string e) :
        code(c), description(d), discount(dis), expiry(e) {}

    // Encapsulation: Getters
    string getCode() const { return code; }
    string getDescription() const { return description; }
    float getDiscount() const { return discount; }
    string getExpiry() const { return expiry; }

    // Setters
    void setDescription(string d) { description = d; }
    void setDiscount(float dis) { discount = dis; }
    void setExpiry(string e) { expiry = e; }

    // Overridden method
    void display() const override {
        cout << left << setw(12) << code
             << setw(25) << description
             << setw(10) << discount
             << expiry << "\n";
    }
};

// Manager class to handle Coupon operations
class CouponManager {
private:
    map<string, CouponDetails*> coupons; // STL Map

public:
    // CREATE Coupon
    void addCoupon(string code, string desc, float discount, string expiry) {
        if (coupons.find(code) != coupons.end())
            throw runtime_error("❌ Coupon already exists!");
        coupons[code] = new CouponDetails(code, desc, discount, expiry);
        cout << "✅ Coupon added successfully!\n";
    }

    // READ all Coupons
    void showAllCoupons() {
        if (coupons.empty()) {
            cout << "📭 No coupons available.\n";
            return;
        }

        cout << "\n🎁 Available Coupons:\n";
        cout << left << setw(12) << "Code"
             << setw(25) << "Description"
             << setw(10) << "Discount"
             << "Expiry\n";
        cout << "----------------------------------------------------------\n";

        for (auto& pair : coupons)
            pair.second->display();
    }

    // UPDATE Coupon
    void updateCoupon(string code, string desc, float discount, string expiry) {
        if (coupons.find(code) == coupons.end())
            throw runtime_error("❌ Coupon not found!");

        coupons[code]->setDescription(desc);
        coupons[code]->setDiscount(discount);
        coupons[code]->setExpiry(expiry);
        cout << "✅ Coupon updated successfully!\n";
    }

    // DELETE Coupon
    void deleteCoupon(string code) {
        auto it = coupons.find(code);
        if (it == coupons.end())
            throw runtime_error("❌ Coupon not found!");

        delete it->second; // Free memory
        coupons.erase(it);
        cout << "🗑️ Coupon deleted successfully!\n";
    }

    // Destructor
    ~CouponManager() {
        for (auto& pair : coupons)
            delete pair.second;
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n🧾 COUPON CODE SYSTEM MENU\n";
    cout << "------------------------------------\n";
    cout << "1. Add Coupon\n";
    cout << "2. Show All Coupons\n";
    cout << "3. Update Coupon\n";
    cout << "4. Delete Coupon\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CouponManager manager;
    int choice;
    string code, description, expiry;
    float discount;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
                case 1:
                    cout << "Enter coupon code: ";
                    getline(cin, code);
                    cout << "Enter description: ";
                    getline(cin, description);
                    cout << "Enter discount (in %): ";
                    cin >> discount;
                    cin.ignore();
                    cout << "Enter expiry date (YYYY-MM-DD): ";
                    getline(cin, expiry);
                    manager.addCoupon(code, description, discount, expiry);
                    break;

                case 2:
                    manager.showAllCoupons();
                    break;

                case 3:
                    cout << "Enter coupon code to update: ";
                    getline(cin, code);
                    cout << "Enter new description: ";
                    getline(cin, description);
                    cout << "Enter new discount: ";
                    cin >> discount;
                    cin.ignore();
                    cout << "Enter new expiry date: ";
                    getline(cin, expiry);
                    manager.updateCoupon(code, description, discount, expiry);
                    break;

                case 4:
                    cout << "Enter coupon code to delete: ";
                    getline(cin, code);
                    manager.deleteCoupon(code);
                    break;

                case 5:
                    cout << "\n👋 Exiting Coupon Code System. Goodbye!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Try again.\n";
            }
        } catch (exception& ex) {
            cout << "❗ Exception: " << ex.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
