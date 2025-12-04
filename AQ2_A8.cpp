#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(0), right(0) {}
};


const int MAX_TREES = 1000;
Node** generateRange(int start, int end, int &count) {
    if (start > end) {
        count = 1;
        Node** arr = new Node*[1];
        arr[0] = 0;          
        return arr;
    }

    Node** result = new Node*[MAX_TREES];
    count = 0;

    for (int rootVal = start; rootVal <= end; ++rootVal) {
        int leftCount = 0, rightCount = 0;
        Node** leftTrees = generateRange(start, rootVal - 1, leftCount);
        Node** rightTrees = generateRange(rootVal + 1, end, rightCount);

        for (int i = 0; i < leftCount; ++i) {
            for (int j = 0; j < rightCount; ++j) {
                Node* root = new Node(rootVal);
                root->left = leftTrees[i];
                root->right = rightTrees[j];
                result[count++] = root;
            }
        }
        delete [] leftTrees;
        delete [] rightTrees;
    }
    return result;
}

Node** generateTrees(int n, int &count) {
    if (n == 0) { count = 0; return 0; }
    return generateRange(1, n, count);
}


void printPre(Node* r) {
    if (!r) { cout << "null "; return; }
    cout << r->val << " ";
    printPre(r->left);
    printPre(r->right);
}

int main() {
    int n = 3;
    int total = 0;
    Node** trees = generateTrees(n, total);

    cout << "Total unique BSTs: " << total << "\n";
    for (int i = 0; i < total; ++i) {
        cout << "Tree " << i + 1 << ": ";
        printPre(trees[i]);
        cout << "\n";
    }
    delete [] trees;
    return 0;
}
