//Program 5: Custom exception using class

#include <iostream>
using namespace std;

class MyException {
public:
    void message() {
        cout << "Custom exception occurred!" << endl;
    }
};

int main() {
    try {
        throw MyException();
    }
    catch (MyException e) {
        e.message();
    }
    return 0;
}
