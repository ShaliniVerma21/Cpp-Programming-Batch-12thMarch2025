//3. Remove Duplicates from an Array

#include <iostream>
#include <set>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    set<int> uniqueElements;
    for (int i = 0; i < n; i++) {
        uniqueElements.insert(arr[i]);
    }
    n = uniqueElements.size();
    int index = 0;
    for (int elem : uniqueElements) {
        arr[index++] = elem;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    removeDuplicates(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return  0;
}