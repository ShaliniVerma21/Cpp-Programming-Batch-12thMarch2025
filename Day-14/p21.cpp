// Program 2: Avoiding Double Delete

#include <iostream>
using namespace std;

class Safe {
public:
    int *p;

    Safe(int val) {
        p = new int(val);
    }

    Safe(const Safe &s) {
        p = new int(*s.p);
    }

    ~Safe() {
        delete p;
    }

    void print() {
        cout << "Value: " << *p << endl;
    }
};

int main() {
    Safe obj1(50), obj2 = obj1;
    obj1.print();
    obj2.print();
    return 0;
}

