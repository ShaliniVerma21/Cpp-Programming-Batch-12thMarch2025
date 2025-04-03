//6. Finding the Minimum Element in an Array
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {7, 2, 8, 1, 5};
    int min = numbers[0];

    for (int i = 1; i < 5; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    cout << "Minimum number: " << min << endl;

    return 0;
}