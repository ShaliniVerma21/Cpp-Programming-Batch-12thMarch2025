//12. Implementing a Binary Search Tree Using Pointers

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* node, int data) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}