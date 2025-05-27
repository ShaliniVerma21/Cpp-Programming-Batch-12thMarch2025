/*
Definition:
Deep copy creates a new object and also creates a new memory for pointer members. 
It copies actual data, not just memory addresses.
Safe & preferred when the object has pointer members.
*/

#include <iostream>
using namespace std;

class Sample {
public:
    int *ptr;
    Sample(int val) {
        ptr = new int(val);
    }

    // Deep copy constructor
    Sample(const Sample &s) {
        ptr = new int(*s.ptr); // Creating new memory and copying data
    }

    void display() {
        cout << "Value: " << *ptr << endl;
    }
};

int main() {
    Sample obj1(10);
    Sample obj2 = obj1; // Deep copy

    *obj1.ptr = 20;
    obj2.display(); // Shows 10, as obj2 has its own copy

    return 0;
}
