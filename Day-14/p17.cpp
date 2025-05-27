//Program 4: Two Objects Sharing Same Pointer

#include <iostream>
using namespace std;

class Share {
public:
    int *ptr;

    Share(int val) {
        ptr = new int(val);
    }

    Share(const Share &s) {
        ptr = s.ptr;
    }

    void print() {
        cout << "Value: " << *ptr << endl;
    }
};

int main() {
    Share obj1(30), obj2 = obj1;
    *obj1.ptr = 50;
    obj2.print();
    return 0;
}
