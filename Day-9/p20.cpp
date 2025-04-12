//6. Merging Two Arrays Using Pointers

#include <iostream>
using namespace std;

void mergeArrays(int* arr1, int size1, int* arr2, int size2, int* merged) {
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof (arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);
    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}