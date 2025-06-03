// Program 2: Min-heap using greater<int>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(10);

    cout << "Lowest: " << minPQ.top() << endl;
    return 0;
}
