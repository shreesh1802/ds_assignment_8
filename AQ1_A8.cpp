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


bool isLeaf(Node* node)
{
    return (node!=nullptr && node->left == nullptr && node->right == nullptr);
}

int SumofLeftLeaves(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int sum = 0;
    
    if(isLeaf(root->left))
    {
        sum += root->left->data;
    }
    else
    {
        sum += SumofLeftLeaves(root->left);
    }
    
    sum += SumofLeftLeaves(root->right);
    
    return sum;
}

int main()
{
    Node* root= new Node(5);
    root->left = new Node(6);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->left->left = new Node(4);
    
    cout << "sum of all leaves: "<<SumofLeftLeaves(root) <<endl;
    
    return 0;
}
