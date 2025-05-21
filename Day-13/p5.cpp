#include <iostream>
using namespace std;

class Point {
public:
    int x; // X coordinate
    int y; // Y coordinate

    // Constructor to initialize point
    Point(int xCoord = 0, int yCoord = 0) : x(xCoord), y(yCoord) {}

    // Overloading the + operator
    Point operator + (const Point& p) {
        Point temp; // Temporary object to hold the result
        temp.x = x + p.x; // Add x coordinates
        temp.y = y + p.y; // Add y coordinates
        return temp; // Return the result
    }
};

int main() {
    Point p1(2, 3); // Create first point (2, 3)
    Point p2(4, 5); // Create second point (4, 5)

    Point result = p1 + p2; // Calls the overloaded + operator
    cout << "Resulting Point: (" << result.x << ", " << result.y << ")" << endl; // Output the result
    return 0;
}