//10. Online Course System (Abstraction + Polymorphism)

#include <iostream>
using namespace std;

class Course {
public:
    virtual void displayCourse() = 0; // abstraction
};

class Programming : public Course {
public:
    void displayCourse() override {
        cout << "Programming Course: C++, Java, Python." << endl;
    }
};

class Design : public Course {
public:
    void displayCourse() override {
        cout << "Design Course: Photoshop, Illustrator." << endl;
    }
};

void showCourseDetails(Course* c) {
    c->displayCourse();
}

int main() {
    Programming prog;
    Design design;

    showCourseDetails(&prog);
    showCourseDetails(&design);

    return 0;
}
