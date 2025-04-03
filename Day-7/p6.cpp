//4. Sorting an Array (Bubble Sort)
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {5, 3, 4, 1, 2};
    int n = 5;

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // Swap
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}