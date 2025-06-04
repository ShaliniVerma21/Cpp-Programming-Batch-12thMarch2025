//15.Hostel Room Allocation

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Abstract base class for Hostel System (Abstraction)
class HostelSystemInterface {
public:
    virtual void allocateRoom() = 0;
    virtual void viewAllotments() = 0;
    virtual void updateStudentRoom() = 0;
    virtual void removeStudent() = 0;
    virtual ~HostelSystemInterface() {}
};

// Student class (Encapsulation)
class Student {
protected:
    int rollNo;
    string name;
    string roomNo;

public:
    // Constructor
    Student(int r, string n, string rm) : rollNo(r), name(n), roomNo(rm) {}

    // Getters and Setters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    string getRoomNo() const { return roomNo; }

    void setRoomNo(string newRoom) {
        roomNo = newRoom;
    }

    // Display student details
    void display() const {
        cout << left << setw(10) << rollNo << setw(20) << name << setw(10) << roomNo << "\n";
    }
};

// Derived class using Inheritance
class HostelRoomManager : public HostelSystemInterface {
private:
    map<int, Student> studentRecords; // STL map: RollNo -> Student
    vector<string> allocatedRooms;    // List of allocated room numbers

public:
    // Allocate room to a student
    void allocateRoom() override {
        int roll;
        string name, room;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore();

        if (studentRecords.find(roll) != studentRecords.end()) {
            cout << "❌ Room already allocated to this roll number.\n";
            return;
        }

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Room Number (e.g., A101): ";
        getline(cin, room);

        if (isRoomAllocated(room)) {
            cout << "❌ Room is already allocated.\n";
            return;
        }

        // Create and insert Student
        Student s(roll, name, room);
        studentRecords[roll] = s;
        allocatedRooms.push_back(room);

        cout << "✅ Room allocated successfully to " << name << ".\n";
    }

    // Check if room is already allocated
    bool isRoomAllocated(const string& room) {
        for (const auto& r : allocatedRooms) {
            if (r == room)
                return true;
        }
        return false;
    }

    // View all students with their room allocation
    void viewAllotments() override {
        cout << "\n📋 Current Hostel Room Allotments\n";
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Room\n";
        cout << "---------------------------------------------------\n";

        for (const auto& [roll, student] : studentRecords) {
            student.display();
        }
    }

    // Update student room
    void updateStudentRoom() override {
        int roll;
        string newRoom;

        cout << "\nEnter Roll Number to Update Room: ";
        cin >> roll;
        cin.ignore();

        auto it = studentRecords.find(roll);
        if (it == studentRecords.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        cout << "Enter New Room Number: ";
        getline(cin, newRoom);

        if (isRoomAllocated(newRoom)) {
            cout << "❌ Room already taken.\n";
            return;
        }

        // Update room number
        string oldRoom = it->second.getRoomNo();
        it->second.setRoomNo(newRoom);

        // Remove old room and add new one
        removeRoom(oldRoom);
        allocatedRooms.push_back(newRoom);

        cout << "✅ Room updated successfully.\n";
    }

    // Remove student from system
    void removeStudent() override {
        int roll;
        cout << "\nEnter Roll Number to Remove: ";
        cin >> roll;

        auto it = studentRecords.find(roll);
        if (it != studentRecords.end()) {
            removeRoom(it->second.getRoomNo());
            studentRecords.erase(it);
            cout << "✅ Student removed successfully.\n";
        } else {
            cout << "❌ Student not found.\n";
        }
    }

    // Remove room from allocated list
    void removeRoom(const string& room) {
        for (auto it = allocatedRooms.begin(); it != allocatedRooms.end(); ++it) {
            if (*it == room) {
                allocatedRooms.erase(it);
                break;
            }
        }
    }
};

// Menu Display
void showMenu() {
    cout << "\n============ 🏨 Hostel Room Allocation Menu ============\n";
    cout << "1. Allocate Room\n";
    cout << "2. View Allotments\n";
    cout << "3. Update Student Room\n";
    cout << "4. Remove Student\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    HostelRoomManager manager;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore(); // consume newline

            switch (choice) {
                case 1: manager.allocateRoom(); break;
                case 2: manager.viewAllotments(); break;
                case 3: manager.updateStudentRoom(); break;
                case 4: manager.removeStudent(); break;
                case 5: cout << "\n👋 Exiting Hostel Management System. Bye!\n"; break;
                default: throw invalid_argument("❌ Invalid option. Please enter a number between 1 and 5.");
            }

        } catch (const exception& e) {
            cout << "\n[Error]: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}
