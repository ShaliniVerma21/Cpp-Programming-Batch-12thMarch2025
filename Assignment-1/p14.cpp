//Problem 13: Course Registration System

#include <iostream>
#include <string>
using namespace std;

struct Course {
    string courseName;
    int courseCode;
};

struct Student {
    string name;
    int rollNumber;
    Course courses[5];
    int courseCount;
};

void registerCourse(Student &student, Course course) {
    if (student.courseCount < 5) {
        student.courses[student.courseCount++] = course;
        cout << "Course " << course.courseName << " registered successfully!" << endl;
    } else {
        cout << "Maximum course limit reached!" << endl;
    }
}

void displayStudentCourses(Student student) {
    cout << "Courses for " << student.name << ":\n";
    for (int i = 0; i < student.courseCount; i++) {
        cout << student.courses[i].courseName << " (Code: " << student.courses[i].courseCode << ")\n";
    }
}

int main() {
    Student student;
    student.courseCount = 0;
    cout << "Enter student name and roll number: ";
    cin >> student.name >> student.rollNumber;

    Course course;
    char choice;
    do {
        cout << "Enter course name and code: ";
        cin >> course.courseName >> course.courseCode;
        registerCourse(student, course);
        cout << "Do you want to register another course? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    displayStudentCourses(student);
    return 0;
}