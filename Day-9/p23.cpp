//9. Implementing a Simple Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    cout << "Linked List: ";
    printList(head);
    return 0;
}