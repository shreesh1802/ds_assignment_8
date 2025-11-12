#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


void BSTtoDLL(Node* root, Node*& head, Node*& tail) {
    if (!root) return;

    
    BSTtoDLL(root->left, head, tail);

   
    Node* newNode = new Node(root->data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->right = newNode;
        newNode->left = tail;
        tail = newNode;
    }

    BSTtoDLL(root->right, head, tail);
}


Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while (head1 && head2) {
        Node* temp;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        } else {
            temp = head2;
            head2 = head2->right;
        }

        if (!head) {
            head = tail = temp;
            head->left = nullptr;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    
    if (head1) tail->right = head1, head1->left = tail;
    if (head2) tail->right = head2, head2->left = tail;

    return head;
}


void printDLL(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}


Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main() {

    Node* root1 = nullptr;
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 5);

    
    Node* root2 = nullptr;
    root2 = insertBST(root2, 8);
    root2 = insertBST(root2, 6);
    root2 = insertBST(root2, 10);

   
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    BSTtoDLL(root1, head1, tail1);
    BSTtoDLL(root2, head2, tail2);

    Node* mergedHead = mergeDLL(head1, head2);

  
    cout << "Merged Sorted Doubly Linked List: ";
    printDLL(mergedHead);

    return 0;
}
