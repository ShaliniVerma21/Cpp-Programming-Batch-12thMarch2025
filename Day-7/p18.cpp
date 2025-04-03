//6. Calculating Factorials Using an Array

#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int factorials[size];

    // Calculate factorials
    for (int i = 1; i <= size; i++) {
        factorials[i - 1] = 1;
        for (int j = 1; j <= i; j++) {
            factorials[i - 1] *= j;
        }
    }

    // Display factorials
    cout << "Factorials from 1 to " << size << ":\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "! = " << factorials[i] << endl;
    }

    return 0;
}