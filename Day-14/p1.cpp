/*
4. Encapsulation, 
5. Multithreading , 
6. Shallow copy & Deep copy
7. Templates
8. Signal Handling
9. Exception handling
10. Assignment-3
*/

#include <iostream>
#include <string>
using namespace std;

struct Address {
    string locality;
    string city;
    string state;
    int pincode;
};

class Person {
protected:
    string name;
    int age;
    string address;
    int DOB;

public:
    // Constructor
    Person() {
    }

    // Virtual Destructor
    virtual ~Person() {
    }

    void setDetails(string n, int a, string addr, int dob) {
        name = n;
        age = a;
        address = addr;
        DOB = dob;
    }

    // Abstract Function
    virtual void displaydetails() = 0;
};

class Student : public Person {
private:
    int roll_number;
    string grade;
    float marks;

public:
    // Constructor
    Student() {
    }

    // Destructor
    virtual ~Student() {
    }

    void inputStudentDetails() {
        cout << "Enter Roll Number: ";
        cin >> roll_number;
        cout << "Enter Grade: ";
        cin >> grade;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displaydetails() override {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address << "\n";
        cout << "DOB: " << DOB << "\n";
        cout << "Roll No: " << roll_number << "\n";
        cout << "Grade: " << grade << "\n";
        cout << "Marks: " << marks << "\n";
    }
};

class Teacher : public Person {
private:
    int id;
    string subject;

public:
    // Constructor
    Teacher() {
    }

    // Destructor
    virtual ~Teacher() {
    }

    void inputTeacherDetails() {
        cout << "Enter Teacher ID: ";
        cin >> id;
        cout << "Enter Subject: ";
        cin >> subject;
    }

    void displaydetails() override {
        cout << "\n--- Teacher Details ---\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address << "\n";
        cout << "DOB: " << DOB << "\n";
        cout << "ID: " << id << "\n";
        cout << "Subject: " << subject << "\n";
    }
};

class School {
private:
    Student studentList[100];
    Teacher teacherList[50];
    int studentCount;
    int teacherCount;

public:
    // Constructor
    School() {
        studentCount = 0;
        teacherCount = 0;
    }

    // Destructor
    virtual ~School() {
    }

    void addStudent() {
        if (studentCount < 100) {
            string name, addr;
            int age, dob;
            cout << "\nEnter Student Name: "; cin >> name;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Address: "; cin >> addr;
            cout << "Enter DOB: "; cin >> dob;

            studentList[studentCount].setDetails(name, age, addr, dob);
            studentList[studentCount].inputStudentDetails();
            studentCount++;
        } else {
            cout << "Student limit reached!\n";
        }
    }

    void addTeacher() {
        if (teacherCount < 50) {
            string name, addr;
            int age, dob;
            cout << "\nEnter Teacher Name: "; cin >> name;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Address: "; cin >> addr;
            cout << "Enter DOB: "; cin >> dob;

            teacherList[teacherCount].setDetails(name, age, addr, dob);
            teacherList[teacherCount].inputTeacherDetails();
            teacherCount++;
        } else {
            cout << "Teacher limit reached!\n";
        }
    }

    void showAllStudents() {
        for (int i = 0; i < studentCount; i++) {
            studentList[i].displaydetails();
        }
    }

    void showAllTeachers() {
        for (int i = 0; i < teacherCount; i++) {
            teacherList[i].displaydetails();
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n======= SCHOOL MENU =======\n";
            cout << "1. Add Student\n";
            cout << "2. Add Teacher\n";
            cout << "3. Show All Students\n";
            cout << "4. Show All Teachers\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addStudent(); break;
                case 2: addTeacher(); break;
                case 3: showAllStudents(); break;
                case 4: showAllTeachers(); break;
                case 5: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice\n"; break;
            }
        } while (choice != 5);
    }
};

int main() {
    School myschool;
    myschool.menu();

    cout<<" Thank you for visiting !" <<endl;
    return 0;

}