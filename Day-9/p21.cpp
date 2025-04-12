//7. Finding Maximum Element in an Array Using Pointers

#include <iostream>
using namespace std;

int findMax(int* arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 5, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum element: " << findMax(arr, size) << endl;
    return 0;
}