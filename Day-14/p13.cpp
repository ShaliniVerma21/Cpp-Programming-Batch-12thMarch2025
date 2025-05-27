/*
Definition-->

Shallow copy creates a new object and copies the values of the original object's data as it is, 
including pointers. It shares the same memory location for pointer members.

Problem -->

If the original or copied object is deleted, the other one might crash (double delete error) 
because they share the same memory.
*/

#include <iostream>
using namespace std;

class Sample {
public:
    int *ptr;
    Sample(int val) {
        ptr = new int(val);
    }

    // Shallow copy constructor
    Sample(const Sample &s) {
        ptr = s.ptr; // Only copying the pointer address
    }

    void display() {
        cout << "Value: " << *ptr << endl;
    }
};

int main() {
    Sample obj1(10);
    Sample obj2 = obj1;  // Shallow copy

    *obj1.ptr = 20;
    obj2.display();  // Shows 20, because ptr is shared

    return 0;
}
