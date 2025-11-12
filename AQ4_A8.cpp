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


vector<int> rightView(Node* root) {
    vector<int> view;
    if (root == nullptr)
        return view;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* lastNode = nullptr;

       
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

         
            lastNode = curr;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        if (lastNode)
            view.push_back(lastNode->data);
    }

    return view;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; i++)
            cin >> nodes[i];

        Node* root = buildTree(nodes);
        vector<int> result = rightView(root);

        for (int val : result)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
