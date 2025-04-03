//8. Counting Occurrences of an Element
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 2, 4};
    int target = 2;
    int count = 0;

    for (int i = 0; i < 5; i++) {
        if (numbers[i] == target) {
            count++;
        }
    }

    cout << "Element " << target << " occurs " << count << " times." << endl;

    return 0;
}