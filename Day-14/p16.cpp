// Program 3: Copy Constructor Without Dynamic Memory

#include <iostream>
using namespace std;

class Test {
public:
    int x;

    Test(int val) {
        x = val;
    }

    void show() {
        cout << "X: " << x << endl;
    }
};

int main() {
    Test a(10);
    Test b = a; // No dynamic memory; safe shallow copy
    b.show();
    return 0;
}
