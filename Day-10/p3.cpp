//3. Student Class

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    float grade;

public:
    Student(string n, int a, float g) {
        name = n;
        age = a;
        grade = g;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

int main() {
    Student student1("Alice", 20, 88.5);
    student1.displayInfo();
    return 0;
}