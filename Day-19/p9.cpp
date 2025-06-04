//9.Stock Portfolio Manager

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>      // for setw
#include <stdexcept>    // for exception handling
using namespace std;

// Abstract base class for Portfolio
class Portfolio {
public:
    virtual void display() const = 0;  // pure virtual function
    virtual ~Portfolio() {}            // virtual destructor
};

// Stock class (derived from Portfolio)
class Stock : public Portfolio {
private:
    string ticker;
    int quantity;
    float price;

public:
    // Constructor
    Stock(string t, int q, float p) : ticker(t), quantity(q), price(p) {}

    // Encapsulation: Getters
    string getTicker() const { return ticker; }
    int getQuantity() const { return quantity; }
    float getPrice() const { return price; }

    // Setters
    void updateQuantity(int q) { quantity = q; }
    void updatePrice(float p) { price = p; }

    // Display method (overridden)
    void display() const override {
        cout << left << setw(10) << ticker
             << setw(10) << quantity
             << "$" << fixed << setprecision(2) << price << "\n";
    }
};

// Manager class to manage all stocks
class StockManager {
private:
    map<string, Stock*> portfolio;  // Map of ticker -> Stock pointer

public:
    // Add new stock
    void addStock(string ticker, int quantity, float price) {
        if (portfolio.find(ticker) != portfolio.end())
            throw runtime_error("Stock already exists!");
        portfolio[ticker] = new Stock(ticker, quantity, price);
        cout << "✅ Stock added successfully!\n";
    }

    // View all stocks
    void viewPortfolio() {
        if (portfolio.empty()) {
            cout << "📭 No stocks in portfolio.\n";
            return;
        }
        cout << "\n📊 Your Portfolio:\n";
        cout << left << setw(10) << "Ticker"
             << setw(10) << "Qty"
             << "Price\n";
        cout << "----------------------------\n";
        for (auto& pair : portfolio)
            pair.second->display();
    }

    // Update stock
    void updateStock(string ticker, int newQty, float newPrice) {
        if (portfolio.find(ticker) == portfolio.end())
            throw runtime_error("❌ Stock not found.");
        portfolio[ticker]->updateQuantity(newQty);
        portfolio[ticker]->updatePrice(newPrice);
        cout << "✅ Stock updated successfully!\n";
    }

    // Delete stock
    void deleteStock(string ticker) {
        auto it = portfolio.find(ticker);
        if (it == portfolio.end())
            throw runtime_error("❌ Stock not found.");
        delete it->second;   // Free memory
        portfolio.erase(it);
        cout << "🗑️ Stock deleted successfully!\n";
    }

    // Destructor
    ~StockManager() {
        for (auto& pair : portfolio)
            delete pair.second;
    }
};

// Menu display function
void showMenu() {
    cout << "\n📈 STOCK PORTFOLIO MANAGER 📉\n";
    cout << "----------------------------------\n";
    cout << "1. Add Stock\n";
    cout << "2. View Portfolio\n";
    cout << "3. Update Stock\n";
    cout << "4. Delete Stock\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    StockManager manager;
    int choice;
    string ticker;
    int qty;
    float price;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear newline

        try {
            switch (choice) {
                case 1:
                    cout << "Enter ticker symbol: ";
                    getline(cin, ticker);
                    cout << "Enter quantity: ";
                    cin >> qty;
                    cout << "Enter price per share: ";
                    cin >> price;
                    manager.addStock(ticker, qty, price);
                    break;

                case 2:
                    manager.viewPortfolio();
                    break;

                case 3:
                    cout << "Enter ticker to update: ";
                    getline(cin >> ws, ticker);
                    cout << "Enter new quantity: ";
                    cin >> qty;
                    cout << "Enter new price: ";
                    cin >> price;
                    manager.updateStock(ticker, qty, price);
                    break;

                case 4:
                    cout << "Enter ticker to delete: ";
                    getline(cin >> ws, ticker);
                    manager.deleteStock(ticker);
                    break;

                case 5:
                    cout << "\n👋 Exiting Portfolio Manager. Thank you!\n";
                    break;

                default:
                    cout << "⚠️ Invalid option! Try again.\n";
            }
        } catch (exception& e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
