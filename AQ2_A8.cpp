#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* clone(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->val);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}


vector<Node*> generateTrees(int start, int end) {
    vector<Node*> result;

    if (start > end) {
        result.push_back(nullptr);
        return result;
    }


    for (int i = start; i <= end; i++) {
        vector<Node*> leftTrees = generateTrees(start, i - 1);
        vector<Node*> rightTrees = generateTrees(i + 1, end);

  
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                Node* root = new Node(i);
                root->left = clone(left);
                root->right = clone(right);
                result.push_back(root);
            }
        }
    }

    return result;
}


vector<Node*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n = 3;
    vector<Node*> trees = generateTrees(n);
    
    cout << "Total unique BSTs for n = " << n << " are: " << trees.size() << endl;
    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        inorder(trees[i]);
        cout << endl;
    }

    return 0;
}
