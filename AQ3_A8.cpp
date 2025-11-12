#include <iostream>
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


int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;


    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);


    return max(leftDepth, rightDepth) + 1;
}

int main() {
  

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum depth of the binary tree = " << maxDepth(root) << endl;
    return 0;
}
