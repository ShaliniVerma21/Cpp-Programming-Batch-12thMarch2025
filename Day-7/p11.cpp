//7. Merging Two Arrays
#include <iostream>
using namespace std;

int main() {
    int array1[3] = {1, 2, 3};
    int array2[3] = {4, 5, 6};
    int merged[6];

    // Merging arrays
    for (int i = 0; i < 3; i++) {
        merged[i] = array1[i];
        merged[i + 3] = array2[i];
    }

    cout << "Merged array: ";
    for (int i = 0; i < 6; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}