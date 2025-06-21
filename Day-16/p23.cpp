//Example 1: Using this to Access Object Members

#include <iostream>
using namespace std;

class Box {
public:
    // Member variable
    double length;

    // Constructor to initialize length
    Box(double length) {
        // Use 'this' to refer to the member variable
        this->length = length; // 'this->length' refers to the member variable
    }

    // Function to display the length
    void displayLength() {
        cout << "Length: " << this->length << endl; // 'this' is optional here
    }
};

int main() {
    Box box(5.0); // Create a Box object with length 5.0
    box.displayLength(); // Call the display function
    return 0;
}
