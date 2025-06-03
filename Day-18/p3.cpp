/*
B. List – Doubly Linked List
➤ Real-World Use: Music playlist (next and previous songs)
*/

//Program 1: Basic list operations
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList = {1, 2, 3};

    // Add elements at front and back
    myList.push_front(0);
    myList.push_back(4);

    // Display elements
    cout << "List: ";
    for(int x : myList)
        cout << x << " ";
    return 0;
}
