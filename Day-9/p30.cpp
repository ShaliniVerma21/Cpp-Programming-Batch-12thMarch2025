//16. Implementing a Sparse Matrix Using Pointers

#include <iostream>
using namespace std;

struct SparseNode {
    int row;
    int col;
    int value;
    SparseNode* next;
};

class SparseMatrix {
private:
    SparseNode* head;

public:
    SparseMatrix() : head(nullptr) {}

    void insert(int row, int col, int value) {
        if (value == 0) return; // No need to store zero values
        SparseNode* newNode = new SparseNode();
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        SparseNode* temp = head;
        while (temp != nullptr) {
            cout << "Row: " << temp->row << ", Col: " << temp->col << ", Value: " << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SparseMatrix sm;
    sm.insert(0, 1, 5);
    sm.insert(1, 0, 3);
    sm.insert(2, 2, 8);
    cout << "Sparse Matrix Elements:" << endl;
    sm.display();
    return 0;
}