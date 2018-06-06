#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node* n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int sizeoftree(Node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        return(sizeoftree(root->left)+1+sizeoftree(root->right));
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int x = sizeoftree(root);
    cout<<"Size of the tree is::"<<x;
    return 0;
}
