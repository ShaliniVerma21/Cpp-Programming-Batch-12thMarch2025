//Example 5: Class to Store and Display Student Info

#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};
int main() {
    Student s;
    s.name = "Ravi";
    s.age = 20;
    s.display();
    return 0;
}
