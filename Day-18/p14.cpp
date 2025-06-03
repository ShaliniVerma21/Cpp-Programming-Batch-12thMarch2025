//Program 2: Multiset – Allow duplicates
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;

    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // Duplicates allowed

    cout << "Multiset: ";
    for(int x : ms)
        cout << x << " ";
    return 0;
}
