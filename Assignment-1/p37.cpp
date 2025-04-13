//11.  a university's student management system

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string rollNumber;
    string course;
    int semester;
    float cgpa;

    Student(string n, string r, string c, int s, float g) {
        name = n;
        rollNumber = r;
        course = c;
        semester = s;
        cgpa = g;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Semester: " << semester << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

class University {
private:
    Student* students;
    int capacity;
    int size;

public:
    University(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        students = new Student[capacity];
    }

    ~University() {
        delete[] students;
    }

    void addStudent(Student student) {
        if (size < capacity) {
            students[size] = student;
            size++;
            cout << "Student added successfully!" << endl;
        } else {
            cout << "University is full. Cannot add more students." << endl;
        }
    }

    void removeStudent(string rollNumber) {
        for (int i = 0; i < size; i++) {
            if (students[i].rollNumber == rollNumber) {
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                cout << "Student removed successfully!" << endl;
                return;
            }
        }
        cout << "Student not found in the university." << endl;
    }

    void displayAllStudents() {
        for (int i = 0; i < size; i++) {
            students[i].displayStudentInfo();
            cout << endl;
        }
    }

    void searchStudent(string rollNumber) {
        for (int i = 0; i < size; i++) {
            if (students[i].rollNumber == rollNumber) {
                students[i].displayStudentInfo();
                return;
            }
        }
        cout << "Student not found in the university." << endl;
    }

    void updateStudentCGPA(string rollNumber, float newCGPA) {
        for (int i = 0; i < size; i++) {
            if (students[i].rollNumber == rollNumber) {
                students[i].cgpa = newCGPA;
                cout << "CGPA updated successfully!" << endl;
                return;
            }
        }
        cout << "Student not found in the university." << endl;
    }
};

int main() {
    University university(100);

    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Update Student CGPA" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, rollNumber, course;
                int semester;
                float cgpa;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student roll number: ";
                cin >> rollNumber;
                cout << "Enter student course: ";
                cin >> course;
                cout << "Enter student semester: ";
                cin >> semester;
                cout << "Enter student CGPA: ";
                cin >> cgpa;
                Student student(name, rollNumber, course, semester, cgpa);
                university.addStudent(student);
                break;
            }
            case 2: {
                string rollNumber;
                cout << "Enter student roll number: ";
                cin >> rollNumber;
                university.removeStudent(rollNumber);
                break;
            }
            case 3:
                university.displayAllStudents();
                break;
            case 4: {
                string rollNumber;
                cout << "Enter student roll number: ";
                cin >> rollNumber;
                university.searchStudent(rollNumber);
                break;
            }
            case 5: {
                string rollNumber;
                float newCGPA;
                cout << "Enter student roll number: ";
                cin >> rollNumber;
                cout << "Enter new CGPA: ";
                cin >> newCGPA;
                university.updateStudentCGPA(rollNumber, newCGPA);
                break;
            }
            case 6:
                cout << " Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}