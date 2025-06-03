// Program 2: Finding an element

#include <iostream>
#include <vector>
#include <algorithm> // Required for find
using namespace std;

int main() {
    vector<string> names = {"John", "Alice", "Bob"};

    // Search for "Alice"
    auto it = find(names.begin(), names.end(), "Alice");

    if(it != names.end())
        cout << "Alice found in list." << endl;
    else
        cout << "Alice not found." << endl;
    return 0;
}
