//Program 2: Access elements and size

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {10, 20, 30};

    cout << "First element: " << dq.front() << endl;
    cout << "Last element: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    return 0;
}
