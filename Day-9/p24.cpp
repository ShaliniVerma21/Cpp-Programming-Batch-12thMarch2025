//10. Implementing a Stack Using Pointers

#include <iostream>
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

void push(Stack** top, int newData) {
    Stack* newNode = new Stack();
    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack** top) {
    if (*top == nullptr) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    Stack* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    delete temp;
    return popped;
}

int main() {
    Stack* top = nullptr;
    push(&top, 10);
    push(&top, 20);
    cout << "Popped element: " << pop(&top) << endl;
    return 0;
}