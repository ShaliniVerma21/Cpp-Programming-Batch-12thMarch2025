//Program 5: Deep Copy and Destructor Safe Use

#include <iostream>
using namespace std;

class Student {
public:
    int *marks;

    Student(int m) {
        marks = new int(m);
    }

    Student(const Student &s) {
        marks = new int(*s.marks);
    }

    ~Student() {
        delete marks;
    }

    void display() {
        cout << "Marks: " << *marks << endl;
    }
};

int main() {
    Student s1(90);
    Student s2 = s1;
    *s1.marks = 100;
    s2.display(); // Will show 90
    return 0;
}
