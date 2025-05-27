// Program 5: Detecting Shared Pointer

#include <iostream>
using namespace std;

class Check {
public:
    int *p;

    Check(int val) {
        p = new int(val);
    }

    Check(const Check &c) {
        p = c.p;
    }

    void compare(Check &c) {
        if (p == c.p)
            cout << "Pointers are shared!" << endl;
        else
            cout << "Pointers are different!" << endl;
    }
};

int main() {
    Check obj1(11), obj2 = obj1;
    obj1.compare(obj2);
    return 0;
}
