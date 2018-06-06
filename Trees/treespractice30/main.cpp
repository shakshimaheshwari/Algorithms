#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *nextRight;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    n->nextRight = NULL;
    return n;
}
void connectRecur(Node* root)
{
    if(root == NULL)
        return;

    if(root->left != NULL)
        root->left->nextRight = root->right;

    if(root->right != NULL)
        root->right->nextRight = (root->nextRight)? root->nextRight->left:NULL;

    connectRecur(root->left);
    connectRecur(root->right);
}
void connect(Node* root)
{
    root->nextRight = NULL;
    connectRecur(root);
}
int main()
{
    Node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);

    // Populates nextRight pointer in all nodes
    connect(root);

    cout<<"Next right of "<<root->data<<" is"<<(root->nextRight? root->nextRight->data:-1);
    cout<<"Next right of "<<root->left->data<<" is"<<(root->left->nextRight? root->left->nextRight->data:-1);


    return 0;
}
