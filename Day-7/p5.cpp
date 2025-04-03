//3. Reversing an Array
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int temp;

    // Reverse the array
    for (int i = 0; i < 5 / 2; i++) {
        temp = numbers[i];
        numbers[i] = numbers[5 - 1 - i];
        numbers[5 - 1 - i] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}