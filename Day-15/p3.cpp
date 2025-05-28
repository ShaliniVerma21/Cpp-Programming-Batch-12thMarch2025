//3. Class Template for a Stack

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(T x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return T(); // Return default value
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack<int> s(5);
    s.push(10);
    s.push(20);
    cout << "Popped element: " << s.pop() << endl;

    return 0;
}