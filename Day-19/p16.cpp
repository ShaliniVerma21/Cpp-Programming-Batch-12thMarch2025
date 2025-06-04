//16.Subject-wise Marks Entry System & Report Card Generator

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

// Abstract class for general student operations
class StudentInterface {
public:
    virtual void addStudent() = 0;
    virtual void enterMarks() = 0;
    virtual void generateReportCard() = 0;
    virtual void deleteStudent() = 0;
    virtual ~StudentInterface() {}
};

// Student class (Encapsulation)
class Student {
private:
    int rollNo;
    string name;
    map<string, int> subjectMarks; // STL map to hold subject-wise marks

public:
    // Constructor
    Student(int roll, string sName) : rollNo(roll), name(sName) {}

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }

    // Add or update marks
    void setMarks(const string& subject, int marks) {
        if (marks < 0 || marks > 100)
            throw invalid_argument("❌ Marks must be between 0 and 100.");
        subjectMarks[subject] = marks;
    }

    // Display report card
    void displayReportCard() const {
        cout << "\n📄 Report Card for " << name << " (Roll No: " << rollNo << ")\n";
        cout << "----------------------------------\n";
        int total = 0;
        for (const auto& [subject, marks] : subjectMarks) {
            cout << subject << ": " << marks << "\n";
            total += marks;
        }
        int subjectCount = subjectMarks.size();
        float average = subjectCount ? static_cast<float>(total) / subjectCount : 0;

        cout << "----------------------------------\n";
        cout << "📊 Total Marks: " << total << "\n";
        cout << "📈 Average: " << fixed << setprecision(2) << average << "\n";
        cout << "🎯 Grade: " << getGrade(average) << "\n";
    }

    // Grade Calculation
    static string getGrade(float average) {
        if (average >= 90) return "A+";
        else if (average >= 80) return "A";
        else if (average >= 70) return "B+";
        else if (average >= 60) return "B";
        else if (average >= 50) return "C";
        else return "F (Fail)";
    }
};

// Derived class using Inheritance
class ReportCardSystem : public StudentInterface {
private:
    map<int, Student> studentMap; // RollNo -> Student

public:
    // Add a student
    void addStudent() override {
        int roll;
        string name;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore();

        if (studentMap.find(roll) != studentMap.end()) {
            cout << "❌ Student already exists.\n";
            return;
        }

        cout << "Enter Student Name: ";
        getline(cin, name);

        Student s(roll, name);
        studentMap[roll] = s;

        cout << "✅ Student added successfully.\n";
    }

    // Enter subject marks
    void enterMarks() override {
        int roll;
        int n;
        string subject;
        int marks;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore();

        if (studentMap.find(roll) == studentMap.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        cout << "Enter number of subjects: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; ++i) {
            cout << "\nEnter Subject Name: ";
            getline(cin, subject);
            cout << "Enter Marks (out of 100): ";
            cin >> marks;
            cin.ignore();

            try {
                studentMap[roll].setMarks(subject, marks);
            } catch (const exception& e) {
                cout << e.what() << "\n";
            }
        }

        cout << "✅ Marks entered successfully.\n";
    }

    // Generate report card
    void generateReportCard() override {
        int roll;
        cout << "\nEnter Roll Number: ";
        cin >> roll;

        if (studentMap.find(roll) == studentMap.end()) {
            cout << "❌ Student not found.\n";
            return;
        }

        studentMap[roll].displayReportCard();
    }

    // Delete student record
    void deleteStudent() override {
        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;

        if (studentMap.erase(roll)) {
            cout << "✅ Student deleted successfully.\n";
        } else {
            cout << "❌ Student not found.\n";
        }
    }
};

// Menu display
void showMenu() {
    cout << "\n=========== 📚 Report Card Menu ===========\n";
    cout << "1. Add Student\n";
    cout << "2. Enter Subject Marks\n";
    cout << "3. Generate Report Card\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    ReportCardSystem system;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: system.addStudent(); break;
                case 2: system.enterMarks(); break;
                case 3: system.generateReportCard(); break;
                case 4: system.deleteStudent(); break;
                case 5: cout << "\n👋 Exiting Report Card System. Thank you!\n"; break;
                default: throw invalid_argument("❌ Invalid choice! Please enter between 1 and 5.");
            }
        } catch (const exception& e) {
            cout << "\n[Error]: " << e.what() << "\n";
        }
    } while (choice != 5);

    return 0;
}
