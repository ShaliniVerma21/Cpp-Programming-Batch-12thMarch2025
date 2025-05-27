//Program 2: Double Deletion Problem

#include <iostream>
using namespace std;

class Test {
public:
    int *x;

    Test(int val) {
        x = new int(val);
    }

    Test(const Test &t) {
        x = t.x;
    }

    ~Test() {
        delete x;
    }
};

int main() {
    Test a(100);
    Test b = a;
    return 0; // May crash due to double delete
}
