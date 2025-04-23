//Real-World Example: A Point structure to represent a point in 2D space.

#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p1;
    p1.x = 10;
    p1.y = 20;
    cout << "Point coordinates: (" << p1.x << ", " << p1.y << ")" << endl;
    return 0;
}
