//12. Online Learning Platform

#include <iostream>
#include <vector>

class Course {
public:
    std::string title;
    std::string instructor;

    Course(std::string t, std::string i) : title(t), instructor(i) {}
};

class Student {
public:
    std::string name;

    Student(std::string n) : name(n) {}
};

class LearningPlatform {
private:
    std::vector<Course> courses;

public:
    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void enrollStudent(const Student& student, const std::string& courseTitle) {
        for (const auto& course : courses) {
            if (course.title == courseTitle) {
                std::cout << student.name << " enrolled in " << course.title << " taught by " << course.instructor << ".\n";
                return;
            }
        }
        std::cout << "Course not found.\n";
    }
};