// Program 1: Basic Deep Copy

#include <iostream>
using namespace std;

class Test {
public:
    int *data;

    Test(int val) {
        data = new int(val);
    }

    Test(const Test &t) {
        data = new int(*t.data);
    }

    void show() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    Test a(5), b = a;
    *a.data = 10;
    b.show(); // Will show 5
    return 0;
}
