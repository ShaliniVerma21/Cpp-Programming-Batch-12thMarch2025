//14. Implementing a Circular Linked List

#include <iostream>
using namespace std;

struct CircularNode {
    int data;
    CircularNode* next;
};

void insert(CircularNode** head, int newData) {
    CircularNode* newNode = new CircularNode();
    newNode->data = newData;
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        CircularNode* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void printList(CircularNode* head) {
    if (head == nullptr) return;
    CircularNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    CircularNode* head = nullptr;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    cout << "Circular Linked List: ";
    printList(head);
    return 0;
}