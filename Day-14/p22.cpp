//Program 3: Deep Copy with Function

#include <iostream>
using namespace std;

class Copy {
public:
    int *data;

    Copy(int val) {
        data = new int(val);
    }

    Copy(const Copy &c) {
        data = new int(*c.data);
    }

    void modify() {
        *data = 100;
    }

    void show() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    Copy a(10), b = a;
    a.modify();
    b.show(); // Will show 10
    return 0;
}
