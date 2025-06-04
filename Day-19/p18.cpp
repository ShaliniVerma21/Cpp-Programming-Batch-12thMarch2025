//18. Student Management System

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

// Abstract base class for managing student info
class StudentInterface {
public:
    virtual void addStudent() = 0;
    virtual void viewStudents() = 0;
    virtual void updateStudent() = 0;
    virtual void deleteStudent() = 0;
    virtual ~StudentInterface() {}
};

// Class to encapsulate student details
class Student {
private:
    int studentID;
    string name;
    int age;
    string department;
    double gpa;

public:
    Student() {}
    Student(int id, string nm, int ag, string dept, double g)
        : studentID(id), name(nm), age(ag), department(dept), gpa(g) {}

    // Getters
    int getID() const { return studentID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getDepartment() const { return department; }
    double getGPA() const { return gpa; }

    // Setters
    void setName(const string& nm) { name = nm; }
    void setAge(int ag) { age = ag; }
    void setDepartment(const string& dept) { department = dept; }
    void setGPA(double g) { gpa = g; }

    void display() const {
        cout << "\n🎓 Student ID: " << studentID
             << "\n👤 Name: " << name
             << "\n🎂 Age: " << age
             << "\n🏫 Department: " << department
             << "\n📊 GPA: " << gpa << "\n";
    }
};

// Derived class implementing Student management system
class StudentManagementSystem : public StudentInterface {
private:
    map<int, Student> studentRecords;

public:
    StudentManagementSystem() {
        cout << "\n📚 Welcome to Student Management System 📚\n";
    }

    // Add new student record
    void addStudent() override {
        int id, age;
        string name, department;
        double gpa;

        cout << "\nEnter Student ID: ";
        cin >> id;
        cin.ignore();

        if (studentRecords.find(id) != studentRecords.end()) {
            cout << "❌ Student ID already exists!\n";
            return;
        }

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        if(age <= 0) {
            cout << "❌ Age must be positive.\n";
            return;
        }

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter GPA (0.0 - 10.0): ";
        cin >> gpa;
        cin.ignore();

        if(gpa < 0.0 || gpa > 10.0) {
            cout << "❌ GPA must be between 0.0 and 10.0\n";
            return;
        }

        Student s(id, name, age, department, gpa);
        studentRecords[id] = s;

        cout << "✅ Student added successfully.\n";
    }

    // View all student records
    void viewStudents() override {
        if (studentRecords.empty()) {
            cout << "\n⚠️ No student records available.\n";
            return;
        }

        cout << "\n========== 🎓 Student Records ==========\n";
        for (auto& pair : studentRecords) {
            pair.second.display();
        }
    }

    // Update an existing student record
    void updateStudent() override {
        int id;
        cout << "\nEnter Student ID to update: ";
        cin >> id;
        cin.ignore();

        auto it = studentRecords.find(id);
        if (it == studentRecords.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        string name, department;
        int age;
        double gpa;

        cout << "Enter new Name: ";
        getline(cin, name);

        cout << "Enter new Age: ";
        cin >> age;
        cin.ignore();

        if(age <= 0) {
            cout << "❌ Age must be positive.\n";
            return;
        }

        cout << "Enter new Department: ";
        getline(cin, department);

        cout << "Enter new GPA (0.0 - 10.0): ";
        cin >> gpa;
        cin.ignore();

        if(gpa < 0.0 || gpa > 10.0) {
            cout << "❌ GPA must be between 0.0 and 10.0\n";
            return;
        }

        it->second.setName(name);
        it->second.setAge(age);
        it->second.setDepartment(department);
        it->second.setGPA(gpa);

        cout << "✅ Student record updated successfully.\n";
    }

    // Delete a student record by ID
    void deleteStudent() override {
        int id;
        cout << "\nEnter Student ID to delete: ";
        cin >> id;
        cin.ignore();

        if (studentRecords.erase(id)) {
            cout << "✅ Student record deleted successfully.\n";
        } else {
            cout << "❌ Student ID not found.\n";
        }
    }
};

// Function to display menu options
void showMenu() {
    cout << "\n\n========== Student Management System Menu ==========\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: sms.addStudent(); break;
                case 2: sms.viewStudents(); break;
                case 3: sms.updateStudent(); break;
                case 4: sms.deleteStudent(); break;
                case 5: cout << "\n👋 Thank you for using Student Management System. Goodbye!\n"; break;
                default: throw invalid_argument("❌ Invalid choice. Please enter 1-5.");
            }
        } catch (const exception& e) {
            cout << "\n[Error] " << e.what() << "\n";
        }
    } while (choice != 5);

    return 0;
}
