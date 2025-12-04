#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(0), right(0) {}
};

struct PtrQueue {
    Node **arr;
    int front, rear, size, cap;

    PtrQueue(int c) {
        cap = c; size = 0; front = 0; rear = 0;
        arr = new Node*[cap];
    }
    ~PtrQueue() { delete [] arr; }

    bool empty() { return size == 0; }

    void push(Node* x) {
        if (size == cap) return; 
        arr[rear] = x;
        rear = (rear + 1) % cap;
        ++size;
    }

    Node* pop() {
        if (size == 0) return 0;
        Node* val = arr[front];
        front = (front + 1) % cap;
        --size;
        return val;
    }
};


Node* buildTree(int *a, int n) {
    if (n == 0 || a[0] == -1) return 0;

    Node *root = new Node(a[0]);
    PtrQueue q(n);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* cur = q.pop();

      
        if (i < n && a[i] != -1) {
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        ++i;

        
        if (i < n && a[i] != -1) {
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        ++i;
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Node* root = buildTree(a, n);
        cout << maxDepth(root) << "\n";

        delete [] a;
        
    }
    return 0;
}
