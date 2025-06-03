/*
G. Set and Multiset

➤ Real-World Use:

Set: Unique usernames
Multiset: Repeated test scores
*/

//Program 1: Set – Unique elements

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {1, 2, 2, 3}; // Duplicate 2 will be removed

    cout << "Set elements: ";
    for(int x : s)
        cout << x << " ";
    return 0;
}
