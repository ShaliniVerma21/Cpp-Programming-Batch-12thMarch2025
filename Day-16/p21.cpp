//Example 2: Star Pattern (Right-Angled Triangle)

#include <iostream>
using namespace std;

int main() {
    // Number of rows for the triangle
    int rows = 5;

    // Loop through each row
    for (int i = 1; i <= rows; i++) {
        // Print stars for the current row
        for (int j = 1; j <= i; j++) {
            cout << "* "; // Print a star followed by a space
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}
