//13. Virtual Classroom System

#include <iostream>
#include <vector>

class Student {
public:
    std::string name;

    Student(std::string n) : name(n) {}
};

class Teacher {
public:
    std::string name;

    Teacher(std::string n) : name(n) {}
};

class Classroom {
private:
    std::vector<Student> students;
    Teacher teacher;

public:
    Classroom(Teacher t) : teacher(t) {}

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayClassroom() const {
        std::cout << "Classroom led by " << teacher.name << ":\n";
        for (const auto& student : students) {
            std::cout << "Student: " << student.name << "\n";
        }
    }
};