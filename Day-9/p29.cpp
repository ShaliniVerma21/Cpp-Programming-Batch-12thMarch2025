//15. Implementing a Priority Queue Using Pointers

#include <iostream>
using namespace std;

struct PriorityQueueNode {
    int data;
    int priority;
    PriorityQueueNode* next;
};

class PriorityQueue {
private:
    PriorityQueueNode* front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(int data, int priority) {
        PriorityQueueNode* newNode = new PriorityQueueNode();
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (front == nullptr || front->priority > priority) {
            newNode->next = front;
            front = newNode;
        } else {
            PriorityQueueNode* temp = front;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        PriorityQueueNode* temp = front;
        int data = front->data;
        front = front->next;
        delete temp;
        return data;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue( 1, 2);
    pq.enqueue(2, 1);
    pq.enqueue(3, 3);
    cout << "Dequeued: " << pq.dequeue() << endl; // Should return 2
    cout << "Dequeued: " << pq.dequeue() << endl; // Should return 1
    return 0;
}