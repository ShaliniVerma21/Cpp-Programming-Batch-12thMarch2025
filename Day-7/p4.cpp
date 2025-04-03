//2. Finding the Sum of Array Elements
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += numbers[i]; // Add each element to sum
    }

    cout << "Sum of array elements: " << sum << endl;

    return 0;
}