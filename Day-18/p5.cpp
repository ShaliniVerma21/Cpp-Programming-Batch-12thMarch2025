/*
 C. Deque – Double Ended Queue
➤ Real-World Use: Train bogies attachable from front or back
*/

//Program 1: Add/remove from both ends
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Add at both ends
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(0);

    // Display
    cout << "Deque: ";
    for(int x : dq)
        cout << x << " ";
    return 0;
}
