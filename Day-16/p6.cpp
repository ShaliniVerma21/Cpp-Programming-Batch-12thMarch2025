//Example 2: Modifying Array Elements

#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an array of integers
    int scores[3] = {85, 90, 78};

    // Modify the second element of the array
    scores[1] = 95; // Changing score from 90 to 95

    // Print the modified array
    for (int i = 0; i < 3; i++) {
        cout << "Score at index " << i << ": " << scores[i] << endl;
    }

    return 0;
}
