#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
   
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class DFS {
public:
    void Preorder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }
};

int main() {
    DFS d1;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    d1.Preorder(root);

    return 0;
}
