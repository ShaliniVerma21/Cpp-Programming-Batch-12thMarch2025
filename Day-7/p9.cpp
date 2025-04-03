//7. Copying an Array
#include <iostream>
using namespace std;

int main() {
    int source[5] = {10, 20, 30, 40, 50};
    int destination[5];

    // Copying elements from source to destination
    for (int i = 0; i < 5; i++) {
        destination[i] = source[i];
    }

    cout << "Copied array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;

    return 0;
}