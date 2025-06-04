//21. Attendance Tracker

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

// ==================== ABSTRACT CLASS ====================
class AttendanceInterface {
public:
    virtual void markAttendance() = 0;
    virtual void viewAttendance() = 0;
    virtual void updateAttendance() = 0;
    virtual void deleteAttendance() = 0;
    virtual ~AttendanceInterface() {}
};

// ==================== STUDENT CLASS ====================
class Student {
private:
    string name;
    int roll;

public:
    Student() {}
    Student(string n, int r) : name(n), roll(r) {}

    void display() const {
        cout << "\tName: " << name << "\n";
        cout << "\tRoll No: " << roll << "\n";
    }

    int getRoll() const {
        return roll;
    }

    string getName() const {
        return name;
    }
};

// ==================== ATTENDANCE CLASS (INHERITANCE, ENCAPSULATION) ====================
class AttendanceSystem : public AttendanceInterface {
private:
    map<int, pair<Student, int>> records; // Roll => <Student, DaysPresent>

public:
    // MARK attendance
    void markAttendance() override {
        string name;
        int roll;
        cout << "\nEnter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();

        if (records.find(roll) != records.end()) {
            records[roll].second++; // Increment attendance
            cout << "\n✔ Attendance marked for " << name << "\n";
        } else {
            Student s(name, roll);
            records[roll] = {s, 1};
            cout << "\n✔ Student added and attendance marked.\n";
        }
    }

    // VIEW attendance
    void viewAttendance() override {
        if (records.empty()) {
            cout << "\n⚠ No records found.\n";
            return;
        }

        cout << "\n===== Attendance Records =====\n";
        for (auto& entry : records) {
            Student s = entry.second.first;
            int days = entry.second.second;
            cout << "\nRoll No: " << s.getRoll() << " | Name: " << s.getName();
            cout << " | Days Present: " << days << "\n";
        }
    }

    // UPDATE attendance
    void updateAttendance() override {
        int roll, newDays;
        cout << "\nEnter Roll Number to update: ";
        cin >> roll;
        cin.ignore();

        if (records.find(roll) == records.end()) {
            throw runtime_error("⚠ Student not found.");
        }

        cout << "Enter updated days present: ";
        cin >> newDays;
        cin.ignore();
        records[roll].second = newDays;
        cout << "\n✔ Attendance updated.\n";
    }

    // DELETE attendance record
    void deleteAttendance() override {
        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;
        cin.ignore();

        if (records.erase(roll)) {
            cout << "\n✔ Record deleted.\n";
        } else {
            throw runtime_error("⚠ Record not found.");
        }
    }
};

// ==================== FUNCTION TO DISPLAY MENU ====================
void menu() {
    cout << "\n\n=========== Attendance Tracker Menu ===========\n";
    cout << "1. Mark Attendance\n";
    cout << "2. View Attendance\n";
    cout << "3. Update Attendance\n";
    cout << "4. Delete Attendance Record\n";
    cout << "5. Exit\n";
    cout << "===============================================\n";
    cout << "Enter your choice: ";
}

// ==================== MAIN FUNCTION ====================
int main() {
    AttendanceSystem system;
    int choice;

    do {
        try {
            menu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: system.markAttendance(); break;
                case 2: system.viewAttendance(); break;
                case 3: system.updateAttendance(); break;
                case 4: system.deleteAttendance(); break;
                case 5: cout << "\nThank you for using the Attendance Tracker!\n"; break;
                default: throw invalid_argument("❌ Invalid choice. Please enter 1-5.");
            }

        } catch (const exception& e) {
            cout << "\n[Error] " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
