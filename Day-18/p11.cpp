/*
 F. Priority Queue – Highest Priority First
➤ Real-World Use: CPU Task Scheduling
*/

//Program 1: Default max-heap behavior
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(40);

    cout << "Highest priority: " << pq.top() << endl;
    pq.pop();
    cout << "Next: " << pq.top() << endl;
    return 0;
}
