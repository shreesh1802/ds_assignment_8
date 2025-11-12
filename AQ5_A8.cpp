#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd,
                      unordered_map<int, int>& inorderIndex) {
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

   
    Node* root = new Node(preorder[preStart]);

 
    int inRoot = inorderIndex[root->data];
    int leftTreeSize = inRoot - inStart;

  
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize,
                                 inorder, inStart, inRoot - 1, inorderIndex);

    root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inorderIndex);

    return root;
}


Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
        inorderIndex[inorder[i]] = i;

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inorderIndex);
}


void printPostorder(Node* root) {
    if (root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> preorder(n), inorder(n);

        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];

        Node* root = buildTree(preorder, inorder);

        // To verify, print postorder traversal
        printPostorder(r
