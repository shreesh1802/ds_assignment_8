#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

   
    if (root->data <= minVal || root->data >= maxVal)
        return false;

  
    return (isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal));
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
  
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if (isBST(root))
        cout << "The given binary tree is a BST." << endl;
    else
        cout << "The given binary tree is NOT a BST." << endl;

    return 0;
}
