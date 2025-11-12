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


Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int& postIndex,
                      unordered_map<int, int>& inorderIndex) {
    if (inStart > inEnd)
        return nullptr;

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

  
    int inRoot = inorderIndex[rootVal];

  
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, postorder, postIndex, inorderIndex);
    root->left = buildTreeHelper(inorder, inStart, inRoot - 1, postorder, postIndex, inorderIndex);

    return root;
}


Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
        inorderIndex[inorder[i]] = i;

    int postIndex = postorder.size() - 1;
    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, postIndex, inorderIndex);
}


void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> inorder(n), postorder(n);
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> postorder[i];

        Node* root = buildTree(inorder, postorder);

        printPreorder(root);
        cout << endl;
    }

    return 0;
}
