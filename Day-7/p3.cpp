//1. Basic Array Declaration and Initialization
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50}; // Declaration and initialization

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}