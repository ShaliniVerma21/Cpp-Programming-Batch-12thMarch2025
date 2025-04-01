//5. Using <vector> for Dynamic Arrays

#include <iostream>
#include <vector> // For vector
using namespace std;

int main() {
    vector<int> numbers;
    int n, input;

    cout << "How many numbers do you want to enter? ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> input;
        numbers.push_back(input); // Add to vector
    }

    cout << "You entered: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}