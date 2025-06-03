/*
 E. Queue – FIFO (First In First Out)
➤ Real-World Use: Line at ticket counter
*/

// Program 1: Basic queue operations

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;

    q.push("Alice");
    q.push("Bob");
    q.push("Charlie");

    cout << "Front: " << q.front() << endl;
    q.pop();
    cout << "Front after pop: " << q.front() << endl;
    return 0;
}
