//11. Implementing a Queue Using Pointers

#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {
            front = newNode;
        }
    }

    int dequeue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        QueueNode* temp = front;
        int value = front->data;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << "Dequeued: " << q.dequeue() << endl;
    return 0;
}