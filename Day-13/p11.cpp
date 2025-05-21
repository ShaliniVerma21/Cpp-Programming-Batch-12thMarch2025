// 2. Inheritance

#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    void work() {
        cout << name << " is working." << endl;
    }
};

class Manager : public Employee {
public:
    void manage() {
        cout << name << " is managing the team." << endl;
    }
};

int main() {
    Manager m1;
    m1.name = "Rahul";
    m1.work();
    m1.manage();
    return 0;
}
