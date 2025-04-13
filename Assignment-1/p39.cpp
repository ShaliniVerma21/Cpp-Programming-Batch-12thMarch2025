//1. Student Management System

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    string rollNumber;
};

void addStudent(Student* students, int& count) {
    cout << "Enter name: ";
    cin >> students[count].name;
    cout << "Enter age: ";
    cin >> students[count].age;
    cout << "Enter roll number: ";
    cin >> students[count].rollNumber;
    count++;
}

void displayStudents(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name << ", Age: " << students[i].age << ", Roll Number: " << students[i].rollNumber << endl;
    }
}

int main() {
    const int MAX_STUDENTS = 100;
    Student* students = new Student[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        cout << "1. Add Student\n2. Display Students\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    delete[] students;
    return 0;
}