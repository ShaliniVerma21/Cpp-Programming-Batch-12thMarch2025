//4. Digital Clock Display,Time Converter (hrs <=> min)

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

// Abstract Base Class (Abstraction)
class ClockBase {
public:
    virtual void display() const = 0;
    virtual ~ClockBase() {}
};

// Clock class (Encapsulation + Inheritance)
class DigitalClock : public ClockBase {
private:
    int hours, minutes;

public:
    // Constructor
    DigitalClock(int h = 0, int m = 0) {
        if (h < 0 || h > 23 || m < 0 || m > 59)
            throw invalid_argument("❌ Invalid time input.");
        hours = h;
        minutes = m;
    }

    // Accessors
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }

    // Display override (Polymorphism)
    void display() const override {
        cout << "⏰ Time: "
             << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << endl;
    }

    // Time to minutes converter
    int toMinutes() const {
        return (hours * 60) + minutes;
    }

    // Set new time (for update)
    void setTime(int h, int m) {
        if (h < 0 || h > 23 || m < 0 || m > 59)
            throw invalid_argument("❌ Invalid time.");
        hours = h;
        minutes = m;
    }
};

// Manager class
class TimeManager {
private:
    vector<DigitalClock*> clocks;

public:
    // Add a time
    void addTime(int h, int m) {
        clocks.push_back(new DigitalClock(h, m));
        cout << "✅ Time added successfully.\n";
    }

    // Display all saved times
    void displayTimes() {
        if (clocks.empty()) {
            cout << "📭 No saved time records.\n";
            return;
        }
        cout << "\n🕐 Saved Times:\n";
        for (size_t i = 0; i < clocks.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            clocks[i]->display();
        }
    }

    // Convert and show minutes from hours
    void convertTimeToMinutes(int index) {
        if (index < 1 || index > clocks.size())
            throw out_of_range("❌ Invalid index.");
        int mins = clocks[index - 1]->toMinutes();
        cout << "🧮 Total Minutes: " << mins << " mins\n";
    }

    // Convert minutes to hours and add as new clock
    void convertMinutesToTime(int mins) {
        if (mins < 0 || mins > 1440)
            throw invalid_argument("❌ Minutes should be between 0 and 1440.");
        int h = mins / 60;
        int m = mins % 60;
        addTime(h, m);
        cout << "✅ Time (" << h << ":" << setw(2) << setfill('0') << m << ") added from " << mins << " minutes.\n";
    }

    // Delete all time records
    void clearAll() {
        for (auto clock : clocks)
            delete clock;
        clocks.clear();
        cout << "🗑️ All time records deleted.\n";
    }

    // Destructor
    ~TimeManager() {
        clearAll();
    }
};

// Menu Display
void showMenu() {
    cout << "\n📌 DIGITAL CLOCK & TIME CONVERTER MENU\n";
    cout << "----------------------------------------\n";
    cout << "1. Add Time (HH MM)\n";
    cout << "2. Display All Times\n";
    cout << "3. Convert Time to Minutes\n";
    cout << "4. Convert Minutes to Time\n";
    cout << "5. Delete All Time Records\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Main Program
int main() {
    TimeManager manager;
    int choice, h, m, index, totalMinutes;

    do {
        showMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter hours (0-23): ";
                    cin >> h;
                    cout << "Enter minutes (0-59): ";
                    cin >> m;
                    manager.addTime(h, m);
                    break;

                case 2:
                    manager.displayTimes();
                    break;

                case 3:
                    cout << "Enter time record index to convert to minutes: ";
                    cin >> index;
                    manager.convertTimeToMinutes(index);
                    break;

                case 4:
                    cout << "Enter total minutes to convert to HH:MM: ";
                    cin >> totalMinutes;
                    manager.convertMinutesToTime(totalMinutes);
                    break;

                case 5:
                    manager.clearAll();
                    break;

                case 6:
                    cout << "👋 Exiting Digital Clock. Goodbye!\n";
                    break;

                default:
                    cout << "⚠️ Invalid option. Try again.\n";
            }
        } catch (exception &e) {
            cout << "❗ Exception: " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}
