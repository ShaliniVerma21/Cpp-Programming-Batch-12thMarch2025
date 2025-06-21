//Example 3: Number Pattern (Pyramid)

#include <iostream>
using namespace std;

int main() {
    // Number of rows for the pyramid
    int rows = 5;

    // Loop through each row
    for (int i = 1; i <= rows; i++) {
        // Print spaces for alignment
        for (int j = i; j < rows; j++) {
            cout << " "; // Print space for alignment
        }
        // Print numbers in the current row
        for (int j = 1; j <= i; j++) {
            cout << j << " "; // Print the current number followed by a space
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}
