//10. Pointer and Struct

#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {10, 20};
    Point* ptr = &p; // Pointer to struct

    cout << "Point coordinates: (" << ptr->x << ", " << ptr->y << ")" << endl; // Accessing struct members using pointer

    return 0;
}