//7. Calendar Event Reminder

#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

// Abstract base class for Event (Abstraction)
class Event {
public:
    virtual void display() const = 0;
    virtual ~Event() {}
};

// Derived class - CalendarEvent (Encapsulation, Inheritance, Polymorphism)
class CalendarEvent : public Event {
private:
    int eventId;
    string title;
    string date;
    string time;
    string description;

public:
    // Constructor
    CalendarEvent(int id, string t, string d, string ti, string desc)
        : eventId(id), title(t), date(d), time(ti), description(desc) {}

    // Getters
    int getId() const { return eventId; }
    string getTitle() const { return title; }

    // Setters
    void setTitle(string t) { title = t; }
    void setDate(string d) { date = d; }
    void setTime(string ti) { time = ti; }
    void setDescription(string desc) { description = desc; }

    // Overridden display method (Polymorphism)
    void display() const override {
        cout << left << setw(5) << eventId
             << setw(15) << title
             << setw(12) << date
             << setw(8) << time
             << description << "\n";
    }
};

// Manager class to handle all CRUD operations
class EventManager {
private:
    map<int, CalendarEvent*> events;
    int idCounter;

public:
    EventManager() : idCounter(1) {}

    // CREATE Event
    void addEvent(string title, string date, string time, string desc) {
        CalendarEvent* newEvent = new CalendarEvent(idCounter, title, date, time, desc);
        events[idCounter] = newEvent;
        cout << "✅ Event added with ID: " << idCounter << "\n";
        idCounter++;
    }

    // READ Events
    void displayAllEvents() {
        if (events.empty()) {
            cout << "📭 No events scheduled.\n";
            return;
        }
        cout << "\n📅 Scheduled Events:\n";
        cout << left << setw(5) << "ID"
             << setw(15) << "Title"
             << setw(12) << "Date"
             << setw(8) << "Time"
             << "Description\n";
        cout << "---------------------------------------------------------\n";
        for (auto& pair : events)
            pair.second->display();
    }

    // UPDATE Event
    void updateEvent(int id, string title, string date, string time, string desc) {
        if (events.find(id) == events.end())
            throw runtime_error("❌ Event ID not found.");
        events[id]->setTitle(title);
        events[id]->setDate(date);
        events[id]->setTime(time);
        events[id]->setDescription(desc);
        cout << "🔁 Event updated successfully!\n";
    }

    // DELETE Event
    void deleteEvent(int id) {
        if (events.find(id) == events.end())
            throw runtime_error("❌ Event ID not found.");
        delete events[id];
        events.erase(id);
        cout << "🗑️ Event deleted successfully!\n";
    }

    // Destructor
    ~EventManager() {
        for (auto& pair : events)
            delete pair.second;
    }
};

// Function to display the main menu
void displayMenu() {
    cout << "\n📆 CALENDAR EVENT REMINDER SYSTEM MENU\n";
    cout << "-----------------------------------------\n";
    cout << "1. Add Event\n";
    cout << "2. Show All Events\n";
    cout << "3. Update Event\n";
    cout << "4. Delete Event\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    EventManager manager;
    int choice, id;
    string title, date, time, desc;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
                case 1:
                    cout << "Enter title: ";
                    getline(cin, title);
                    cout << "Enter date (YYYY-MM-DD): ";
                    getline(cin, date);
                    cout << "Enter time (HH:MM): ";
                    getline(cin, time);
                    cout << "Enter description: ";
                    getline(cin, desc);
                    manager.addEvent(title, date, time, desc);
                    break;

                case 2:
                    manager.displayAllEvents();
                    break;

                case 3:
                    cout << "Enter event ID to update: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter new title: ";
                    getline(cin, title);
                    cout << "Enter new date: ";
                    getline(cin, date);
                    cout << "Enter new time: ";
                    getline(cin, time);
                    cout << "Enter new description: ";
                    getline(cin, desc);
                    manager.updateEvent(id, title, date, time, desc);
                    break;

                case 4:
                    cout << "Enter event ID to delete: ";
                    cin >> id;
                    cin.ignore();
                    manager.deleteEvent(id);
                    break;

                case 5:
                    cout << "👋 Exiting Calendar Event System. Goodbye!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Try again.\n";
            }
        } catch (exception& e) {
            cout << "❗ Exception: " << e.what() << "\n";
        }
    } while (choice != 5);

    return 0;
}
