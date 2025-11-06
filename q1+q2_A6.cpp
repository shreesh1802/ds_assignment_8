#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root; 
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}


Node* findMax(Node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == nullptr)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
       
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


Node* inorderSuccessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;

   
    if (node->right != nullptr)
        return findMin(node->right);

   
    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}


Node* inorderPredecessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;

    
    if (node->left != nullptr)
        return findMax(node->left);

    
    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    if (!root->left && !root->right)
        return 1;
    
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}



int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of elements to insert in BST: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal (sorted): ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

   
    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    cout << "\nMinimum value in BST: " << (minNode ? minNode->data : -1);
    cout << "\nMaximum value in BST: " << (maxNode ? maxNode->data : -1);

    int val;
    cout<< "Enter value to delete: " << endl;
    cin >> val;
    deleteNode(root , val);
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout <<"Maximum depth of tree: ";
    maxDepth(root);

    cout <<"Minimum depth of tree: ";
    minDepth(root);

    int key;
    cout <<"Search for an element in tree: ";
    cin >> key;
    search(root,key);
    
    
    cout << "\n\nEnter a value to find its inorder successor and predecessor: ";
    cin >> value;
    Node* node = search(root, value);

    if (node == nullptr) {
        cout << value << " not found in BST.\n";
    } else {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);

        cout << "\nInorder Successor of " << value << ": ";
        if (succ)
            cout << succ->data;
        else
            cout << "None";

        cout << "\nInorder Predecessor of " << value << ": ";
        if (pred)
            cout << pred->data;
        else
            cout << "None";
        cout << endl;
    }

    return 0;
}
