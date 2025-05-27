//Program 4: Deep Copy Detection

#include <iostream>
using namespace std;

class Check {
public:
    int *ptr;

    Check(int val) {
        ptr = new int(val);
    }

    Check(const Check &c) {
        ptr = new int(*c.ptr);
    }

    void compare(Check &c) {
        if (ptr != c.ptr)
            cout << "Pointers are different (deep copy)." << endl;
        else
            cout << "Pointers are same (shallow copy)." << endl;
    }
};

int main() {
    Check obj1(11), obj2 = obj1;
    obj1.compare(obj2);
    return 0;
}
