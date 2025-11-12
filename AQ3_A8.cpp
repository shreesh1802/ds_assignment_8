#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

  
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;

  
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    int T;
    cin >> T; \

    while (T--) {
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
        }

        Node* root = buildTree(nodes);
        cout << maxDepth(root) << endl;
    }

    return 0;
}
