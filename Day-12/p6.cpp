//Student Attendance System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for attendance status
enum class AttendanceStatus {
    PRESENT,
    ABSENT,
    LATE
};

// Structure for a student
struct Student {
    string name; // Name of the student
    int id; // Student ID
    vector<AttendanceStatus> attendance; // Attendance record

    // Constructor for Student
    Student(string n, int i) : name(n), id(i) {
        // Initialize attendance record with a default value (ABSENT)
        attendance.resize(30, AttendanceStatus::ABSENT); // Assuming 30 days in a month
    }

    // Function to record attendance
    void recordAttendance(int day, AttendanceStatus status) {
        if (day >= 1 && day <= 30) {
            attendance[day - 1] = status; // Record attendance for the specified day
        }
    }

    // Function to calculate attendance percentage
    double calculateAttendancePercentage() const {
        int totalClasses = attendance.size();
        int presentCount = count(attendance.begin(), attendance.end(), AttendanceStatus::PRESENT);
        return (static_cast<double>(presentCount) / totalClasses) * 100.0;
    }
};

// Base class for AttendanceSystem
class AttendanceSystem {
protected:
    vector<Student> students; // List of students

public:
    // Function to add a student
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Function to display all students and their attendance
    void displayStudents() const {
        cout << "Student Attendance:\n";
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name
                 << ", Attendance Percentage: " << fixed << setprecision(2)
                 << student.calculateAttendancePercentage() << "%\n";
        }
    }

    // Function to record attendance for a student
    void recordAttendance(int studentId, int day, AttendanceStatus status) {
        for (auto& student : students) {
            if (student.id == studentId) {
                student.recordAttendance(day, status);
                return;
            }
        }
        cout << "Student ID " << studentId << " not found.\n";
    }

    // Virtual destructor
    virtual ~AttendanceSystem() {}
};

// Derived class for ExtendedAttendanceSystem
class ExtendedAttendanceSystem : public AttendanceSystem {
public:
    // Function to display detailed attendance report for each student
    void displayDetailedReport() const {
        cout << "=== Detailed Attendance Report ===\n";
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name << "\n";
            cout << "Attendance Record:\n";
            for (size_t i = 0; i < student.attendance.size(); ++i) {
                cout << "Day " << (i + 1) << ": " 
                     << (student.attendance[i] == AttendanceStatus::PRESENT ? "Present" :
                         student.attendance[i] == AttendanceStatus::ABSENT ? "Absent" : "Late") << "\n";
            }
            cout << "Attendance Percentage: " << fixed << setprecision(2)
                 << student.calculateAttendancePercentage() << "%\n\n";
        }
    }
};

int main() {
    // Create an instance of ExtendedAttendanceSystem
    ExtendedAttendanceSystem attendanceSystem;

    // Add students to the attendance system
    attendanceSystem.addStudent(Student("Alice", 101));
    attendanceSystem.addStudent(Student("Bob", 102));
    attendanceSystem.addStudent(Student("Charlie", 103));

    // Record attendance for students
    attendanceSystem.recordAttendance(101, 1, AttendanceStatus::PRESENT);
    attendanceSystem.recordAttendance(101, 2, AttendanceStatus::LATE);
    attendanceSystem.recordAttendance(102, 1, AttendanceStatus::ABSENT);
    attendanceSystem.recordAttendance(102, 2, AttendanceStatus::PRESENT);
    attendanceSystem.recordAttendance(103, 1, AttendanceStatus::PRESENT);
    attendanceSystem.recordAttendance(103, 2, AttendanceStatus::PRESENT);

    // Display all students and their attendance
    attendanceSystem.displayStudents();
    cout << endl;

    // Display detailed attendance report
    attendanceSystem.displayDetailedReport();

    return 0;
}