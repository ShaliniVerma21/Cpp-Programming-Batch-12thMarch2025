//3. Leap Year Checker

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract base class (Abstraction)
class YearBase {
public:
    virtual bool isLeap() const = 0;
    virtual void display() const = 0;
    virtual ~YearBase() {}
};

// Derived class (Inheritance + Encapsulation)
class LeapYear : public YearBase {
private:
    int year;

public:
    // Constructor with validation
    LeapYear(int y) {
        if (y < 0)
            throw invalid_argument("❌ Year cannot be negative.");
        year = y;
    }

    // Getter
    int getYear() const { return year; }

    // Leap year logic (Polymorphism)
    bool isLeap() const override {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    // Display year status
    void display() const override {
        cout << "📅 Year " << year << " is "
             << (isLeap() ? "a Leap Year ✅" : "not a Leap Year ❌") << endl;
    }
};

// Manager class for CRUD operations
class LeapYearManager {
private:
    vector<LeapYear*> yearList;

public:
    // Create/Add
    void addYear(int y) {
        yearList.push_back(new LeapYear(y));
        cout << "✅ Year " << y << " added successfully.\n";
    }

    // Read/Display
    void displayYears() const {
        if (yearList.empty()) {
            cout << "📭 No years saved yet.\n";
            return;
        }

        cout << "\n📜 Leap Year Check Results:\n";
        for (size_t i = 0; i < yearList.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            yearList[i]->display();
        }
    }

    // Delete All
    void clearAll() {
        for (LeapYear* y : yearList)
            delete y;
        yearList.clear();
        cout << "🗑️ All records deleted.\n";
    }

    // Destructor
    ~LeapYearManager() {
        clearAll();
    }
};

// Function to display the menu
void showMenu() {
    cout << "\n📌 LEAP YEAR CHECKER MENU\n";
    cout << "-------------------------------\n";
    cout << "1. Add Year\n";
    cout << "2. Show All Years\n";
    cout << "3. Delete All Records\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    LeapYearManager manager;
    int choice;
    int year;

    do {
        showMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter year to check: ";
                    cin >> year;
                    manager.addYear(year);
                    break;

                case 2:
                    manager.displayYears();
                    break;

                case 3:
                    manager.clearAll();
                    break;

                case 4:
                    cout << "👋 Exiting Leap Year Checker. Goodbye!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "❗ Exception: " << e.what() << "\n";
        }

    } while (choice != 4);

    return 0;
}
