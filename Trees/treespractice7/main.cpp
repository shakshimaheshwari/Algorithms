#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void deleteNode(Node *root)
{
    if(root == NULL)
        return;

    deleteNode(root->left);
    deleteNode(root->right);

    cout<<"Deleting node"<<root->data;
    delete(root);
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    deleteNode(root);
    return 0;
}
