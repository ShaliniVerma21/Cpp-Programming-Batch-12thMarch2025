// Program 2: Functor for descending order sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functor to sort in descending order
class Descending {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    vector<int> nums = {30, 10, 50, 20};

    // Use functor with sort
    sort(nums.begin(), nums.end(), Descending());

    // Display result
    cout << "Sorted (Descending): ";
    for(int x : nums)
        cout << x << " ";
    return 0;
}
