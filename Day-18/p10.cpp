//Program 2: Display full queue

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Adding elements
    for(int i = 1; i <= 3; i++)
        q.push(i);

    // Display and empty
    while(!q.empty()) {
        cout << "Serving: " << q.front() << endl;
        q.pop();
    }
    return 0;
}
