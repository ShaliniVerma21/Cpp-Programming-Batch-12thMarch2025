//3. Finding the Maximum Element in an Array
#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int numbers[size];

    // Input numbers
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Find maximum
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    cout << "Maximum number: " << max << endl;

    return 0;
}